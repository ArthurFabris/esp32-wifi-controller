#include <string.h>
#include <esp_spiffs.h>

#include "esp_event.h"
#include "esp_log.h"
#include "esp_wifi.h"
#include "esp_netif.h"
#include "esp_http_server.h"
#include "nvs_flash.h"
#include "driver/gpio.h"


/*---------------------------------------------------------------------------*/
// Defina o nome da sua network:(SSID)
#define WIFI_SSID "Controle"
/*---------------------------------------------------------------------------*/
// Defina a senha da sua network
#define WIFI_PASS "123456789"
/*---------------------------------------------------------------------------*/
// Defina quantos controles simultaneos o robo aceita
#define MAX_STA_CONN 2
/*---------------------------------------------------------------------------*/
#define UP_PIN        GPIO_NUM_4  // Pino de movimento do robo para cima
#define DOWN_PIN      GPIO_NUM_5  // Pino de movimento do robo para baixo
#define LEFT_PIN      GPIO_NUM_18 // Pino de movimento do robo para a esquerda
#define RIGHT_PIN     GPIO_NUM_19 // Pino de movimento do robo para a direita
/*-----------------------------------------------------------*/
#define ON_PIN        GPIO_NUM_23 // Verifica se o servidor HTTPS esta rodando (opcional)
#define CONNECTED_PIN GPIO_NUM_22 // quando um controle esta conectado no robo (opcional)
/*---------------------------------------------------------------------------*/
//Defina o nome do seu controle
static const char *TAG = "Controle";
/*---------------------------------------------------------------------------*/


void init_gpio() {
    gpio_config_t io_conf;

    // Configure UP_PIN
    io_conf.intr_type = GPIO_INTR_DISABLE;
    io_conf.mode = GPIO_MODE_OUTPUT;
    io_conf.pin_bit_mask = (1ULL << UP_PIN);
    io_conf.pull_down_en = 0;
    io_conf.pull_up_en = 0;
    gpio_config(&io_conf);

    // Configure DOWN_PIN
    io_conf.pin_bit_mask = (1ULL << DOWN_PIN);
    gpio_config(&io_conf);

    // Configure LEFT_PIN
    io_conf.pin_bit_mask = (1ULL << LEFT_PIN);
    gpio_config(&io_conf);

    // Configure RIGHT_PIN
    io_conf.pin_bit_mask = (1ULL << RIGHT_PIN);
    gpio_config(&io_conf);

    // Configure ON_PIN
    io_conf.pin_bit_mask = (1ULL << ON_PIN);
    gpio_config(&io_conf);
    gpio_set_level(ON_PIN, 0); // Initially OFF

    // Configure CONNECTED_PIN
    io_conf.pin_bit_mask = (1ULL << CONNECTED_PIN);
    gpio_config(&io_conf);
    gpio_set_level(CONNECTED_PIN, 0); // Initially OFF
}

// Inicialização do SPIFFS
static void init_spiffs(void)
{
    esp_vfs_spiffs_conf_t conf = {
      .base_path = "/spiffs",
      .partition_label = NULL,
      .max_files = 5,
      .format_if_mount_failed = true
    };

    esp_err_t ret = esp_vfs_spiffs_register(&conf);

    if (ret != ESP_OK) {
        if (ret == ESP_FAIL) {
            ESP_LOGE(TAG, "Falha em montar o sistema de arquivos (filesystem)");
        } else if (ret == ESP_ERR_NOT_FOUND) {
            ESP_LOGE(TAG, "Falha em iniciar a partição SPIFFS");
        } else {
            ESP_LOGE(TAG, "Falha em iniciar SPIFFS. (%s)", esp_err_to_name(ret));
        }
        return;
    }

    size_t total = 0, used = 0;
    ret = esp_spiffs_info(NULL, &total, &used);
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Falha ao obter informações da partição SPIFFS. (%s)", esp_err_to_name(ret));
    } else {
        ESP_LOGI(TAG, "Tamanho da particao: total: %d, usado: %d", total, used);
    }
}

/* HTTP GET handler */
static esp_err_t hello_get_handler(httpd_req_t *req)
{
    FILE* f = fopen("/spiffs/index.html", "r");
    if (f == NULL) {
        ESP_LOGE(TAG, "Cannot open file");
        httpd_resp_send_404(req);
        return ESP_FAIL;
    }

    char line[256];
    while (fgets(line, sizeof(line), f) != NULL) {
        httpd_resp_send_chunk(req, line, strlen(line));
    }
    fclose(f);
    httpd_resp_send_chunk(req, NULL, 0);  // Indicate end of response
    return ESP_OK;
}

/* URI handler for buttons */

/* O ESP_LOGI nao consegue dar display de mais de uma acao por vez
 * ou seja, mesmo que 2 ou mais botoes sejam precionados ele so vai
 * dar o LOG de 1 desses botoes, geralmente o que foi apertado por ultimo
 * porem, ele consegue capturar mais de um botao, por que todos sao IF e nao else if
 */

static esp_err_t button_handler(httpd_req_t *req)
{
    char* state = strstr(req->uri, "state=");
    if (state != NULL) {
        state += strlen("state=");

        char* button = req->uri + 7;
        //-------------------------------------------------------------
        if (strcmp(button, "up?state=pressed") == 0 && strcmp(state, "pressed") == 0)
        {
            ESP_LOGI(TAG, "Up button pressed");
            gpio_set_level(UP_PIN, 1); // Turn on UP_PIN
        }
        if (strcmp(button, "up?state=released") == 0 && strcmp(state, "released") == 0)
        {
            ESP_LOGI(TAG, "Up button released");
            gpio_set_level(UP_PIN, 0); // Turn off UP_PIN
        }
        //-------------------------------------------------------------
        if (strcmp(button, "down?state=pressed") == 0 && strcmp(state, "pressed") == 0)
        {
            ESP_LOGI(TAG, "Down button pressed");
            gpio_set_level(DOWN_PIN, 1); // Turn on DOWN_PIN
        }
        if (strcmp(button, "down?state=released") == 0 && strcmp(state, "released") == 0)
        {
            ESP_LOGI(TAG, "Down button released");
            gpio_set_level(DOWN_PIN, 0); // Turn off DOWN_PIN
        }
        //-------------------------------------------------------------
        if (strcmp(button, "left?state=pressed") == 0 && strcmp(state, "pressed") == 0)
        {
            ESP_LOGI(TAG, "Left button pressed");
            gpio_set_level(LEFT_PIN, 1); // Turn on LEFT_PIN
        }
        if (strcmp(button, "left?state=released") == 0 && strcmp(state, "released") == 0)
        {
            ESP_LOGI(TAG, "Left button released");
            gpio_set_level(LEFT_PIN, 0); // Turn off LEFT_PIN
        }
        //-------------------------------------------------------------
        if (strcmp(button, "right?state=pressed") == 0 && strcmp(state, "pressed") == 0)
        {
            ESP_LOGI(TAG, "Right button pressed");
            gpio_set_level(RIGHT_PIN, 1); // Turn on RIGHT_PIN
        }
        if (strcmp(button, "right?state=released") == 0 && strcmp(state, "released") == 0)
        {
            ESP_LOGI(TAG, "Right button released");
            gpio_set_level(RIGHT_PIN, 0); // Turn off RIGHT_PIN
        }
        //-------------------------------------------------------------
    }
    httpd_resp_send(req, "Estado do botão mudou.", HTTPD_RESP_USE_STRLEN);
    return ESP_OK;
}

void register_server_handlers(httpd_handle_t server)
{
    httpd_uri_t uri_get = {
        .uri = "/",
        .method = HTTP_GET,
        .handler = hello_get_handler,
        .user_ctx = NULL
    };
    httpd_register_uri_handler(server, &uri_get);

    httpd_uri_t uri_button = {
        .uri = "/button*",
        .method = HTTP_GET,
        .handler = button_handler,
        .user_ctx = NULL
    };
    httpd_register_uri_handler(server, &uri_button);
}

static void start_http_server(void)
{
    httpd_handle_t server = NULL;
    httpd_config_t config = HTTPD_DEFAULT_CONFIG();

    if (httpd_start(&server, &config) == ESP_OK) {
        // Register root URI handler
        httpd_uri_t root = {
            .uri       = "/",
            .method    = HTTP_GET,
            .handler   = hello_get_handler,
            .user_ctx  = NULL
        };
        httpd_register_uri_handler(server, &root);

        // Register button URI handlers
        const char *directions[] = {"up", "down", "left", "right"};
        for (int i = 0; i < 4; i++) {
            char uri[20];
            sprintf(uri, "/button%s", directions[i]);
            httpd_uri_t button = {
                .uri       = uri,
                .method    = HTTP_GET,
                .handler   = button_handler,
                .user_ctx  = NULL
            };
            httpd_register_uri_handler(server, &button);
        }
    }
    // Light up the ON_PIN when server is ready
    gpio_set_level(ON_PIN, 1);
}

static void wifi_event_handler(void* arg, esp_event_base_t event_base,
                               int32_t event_id, void* event_data)
{
    if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_AP_STACONNECTED) {
        ESP_LOGI(TAG, "Estacao conectou");
        gpio_set_level(CONNECTED_PIN, 1); // Turn on CONNECTED_PIN
    } else if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_AP_STADISCONNECTED) {
        ESP_LOGI(TAG, "Estacao desconectou");
        gpio_set_level(CONNECTED_PIN, 0); // Turn off CONNECTED_PIN
    }
}

static void wifi_init_softap(void)
{
    esp_netif_create_default_wifi_ap();

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    esp_wifi_init(&cfg);

    wifi_config_t wifi_config = {
        .ap = {
            .ssid = WIFI_SSID,
            .ssid_len = strlen(WIFI_SSID),
            .channel = 1,
            .password = WIFI_PASS,
            .max_connection = MAX_STA_CONN,
            .authmode = WIFI_AUTH_WPA_WPA2_PSK
        },
    };

    if (strlen(WIFI_PASS) == 0) {
        wifi_config.ap.authmode = WIFI_AUTH_OPEN;
    }

    esp_wifi_set_mode(WIFI_MODE_AP);
    esp_wifi_set_config(WIFI_IF_AP, &wifi_config);
    esp_wifi_start();

    ESP_LOGI(TAG, "Rede wifi Funcionando: SSID:%s password:%s",
             wifi_config.ap.ssid, wifi_config.ap.password);

    // Register event handler for Wi-Fi
    ESP_ERROR_CHECK(esp_event_handler_instance_register(WIFI_EVENT,
                                                        ESP_EVENT_ANY_ID,
                                                        &wifi_event_handler,
                                                        NULL,
                                                        NULL));
}

void app_main(void)
{
    // Initialize NVS
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);

    esp_netif_init();
    esp_event_loop_create_default();

    // Inicializar SPIFFS
    init_spiffs();
    init_gpio();
    wifi_init_softap();
    start_http_server();
}
