#include <SPIFFS.h>

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  initSPIFFS();

  Serial.println("Systém je připraven. Očekávané příkazy ve formátu:");
  Serial.println(" - Nastav jas na X %");
  Serial.println(" - Uprav jas na X %");
  Serial.println(" - Sniž jas na X %");
  Serial.println(" - Zvyš jas na X %");
}

void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    command.trim();

    Serial.print("Přijatý příkaz: ");
    Serial.println(command);

    int startIndex = command.indexOf("na") + 3;
    int endIndex = command.indexOf("%");
    String percentageString = command.substring(startIndex, endIndex);
    percentageString.trim();

    int percentage = percentageString.toInt();

    if (percentage >= 0 && percentage <= 100) {
      int pwm_value = map(percentage, 0, 100, 0, 255);

      // Nastavení jasu LED
      rgbLedWrite(LED_BUILTIN, pwm_value, pwm_value, pwm_value);

      Serial.print("Nastaven jas LED na: ");
      Serial.print(percentage);
      Serial.println(" %");
    } else Serial.println("Chyba: Hodnota jasu musí být v rozsahu 0–100 %.");
  }
}

void loadWeightsOrBiases(const char* filename, float* array, int array_size) {
  File file = SPIFFS.open(filename, "r");
  if (!file) {
    Serial.print("Chyba při otevírání souboru: ");
    Serial.println(filename);
    return;
  }

  String content = file.readString();
  file.close();

  int index = 0;
  char* token = strtok((char*)content.c_str(), ",");
  while (token != nullptr && index < array_size) {
    array[index++] = atof(token);
    token = strtok(nullptr, ",");
  }
}

void initSPIFFS() {
  if (!SPIFFS.begin(true)) {
    Serial.println("SPIFFS inicializace selhala!");
    while (true)
      ;
  }
  Serial.println("SPIFFS inicializováno.");
}