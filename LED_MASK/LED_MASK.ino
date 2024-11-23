#include <Adafruit_NeoPixel.h> // Include the Adafruit NeoPixel library to control the LED strips

// Define hardware connections and configuration
#define LED_PIN1 A1  // Pin connected to the data line of the first LED strip
#define LED_PIN2 A2  // Pin connected to the data line of the second LED strip
#define BUTTON_PIN1 A3 // Pin connected to button 1
#define BUTTON_PIN2 A4 // Pin connected to button 2
#define BUTTON_PIN3 A5 // Pin connected to button 3
#define NUM_LEDS 90    // Number of LEDs per strip

// Create NeoPixel objects for both LED strips
Adafruit_NeoPixel strip1(NUM_LEDS, LED_PIN1, NEO_GRB + NEO_KHZ800); // Define first LED strip
Adafruit_NeoPixel strip2(NUM_LEDS, LED_PIN2, NEO_GRB + NEO_KHZ800); // Define second LED strip

void setup() {
  // Initialize both LED strips
  strip1.begin(); // Prepare the first LED strip for use
  strip2.begin(); // Prepare the second LED strip for use
  strip1.show();  // Turn off all LEDs on the first strip
  strip2.show();  // Turn off all LEDs on the second strip

  // Configure button pins as inputs with internal pull-up resistors
  pinMode(BUTTON_PIN1, INPUT_PULLUP); // Button 1 (pressed state = LOW)
  pinMode(BUTTON_PIN2, INPUT_PULLUP); // Button 2 (pressed state = LOW)
  pinMode(BUTTON_PIN3, INPUT_PULLUP); // Button 3 (pressed state = LOW)
}

void loop() {
  // Check button states and execute corresponding functions
  if (digitalRead(BUTTON_PIN1) == LOW && digitalRead(BUTTON_PIN2) == LOW && digitalRead(BUTTON_PIN3) == LOW) {
    crazy(); // If all three buttons are pressed, display the "crazy" animation
  } 
  else if (digitalRead(BUTTON_PIN1) == LOW && digitalRead(BUTTON_PIN2) == LOW) {
    smirk(); // If button 1 and button 2 are pressed, display the "smirk" animation
  } 
  else if (digitalRead(BUTTON_PIN2) == LOW && digitalRead(BUTTON_PIN3) == LOW) {
    eager(); // If button 2 and button 3 are pressed, display the "eager" animation
  } 
  else if (digitalRead(BUTTON_PIN1) == LOW) {
    talking(); // If only button 1 is pressed, display the "talking" animation
  } 
  else if (digitalRead(BUTTON_PIN2) == LOW) {
    mad(); // If only button 2 is pressed, display the "mad" animation
  } 
  else if (digitalRead(BUTTON_PIN3) == LOW) {
    dead(); // If only button 3 is pressed, display the "dead" animation
  } 
  else {
    happy(); // If no buttons are pressed, display the "happy" animation
  }
}

// Animation functions

// Displays a "happy" face with blue eyes and a smile
void happy() {
  shutdown();           // Turn off all LEDs before starting
  eyes(0, 0, 255);      // Set eyes to blue
  smile1(0, 0, 255);    // Display a blue smile
}

// Displays a "talking" face with blue eyes and an open mouth
void talking() {
  shutdown();           // Turn off all LEDs before starting
  eyes(0, 0, 255);      // Set eyes to blue
  open(0, 0, 255);      // Display an open mouth in blue
}

// Displays a "mad" face with red frown, eyes, and eyebrows
void mad() {
  shutdown();           // Turn off all LEDs before starting
  frown(255, 0, 0);     // Set the frown to red
  eyes(255, 0, 0);      // Set the eyes to red
  brows(255, 0, 0);     // Set the eyebrows to red
}

// Displays a "smirk" face with green features
void smirk() {
  shutdown();           // Turn off all LEDs before starting
  chink(0, 255, 0);     // Set the eyes to a green chinky pattern
  brows(0, 255, 0);     // Set the eyebrows to green
  wide(0, 255, 0);      // Display a wide green smile
}

// Displays a "dead" face with a red X on eyes and white surprise features
void dead() {
  shutdown();           // Turn off all LEDs before starting
  xmark(255, 0, 0);     // Display a red X mark on the eyes
  wow(255, 255, 255);   // Display a white surprise feature
  eyes(255, 255, 255);  // Set the eyes to white
}

// Displays an "eager" face with purple features
void eager() {
  shutdown();           // Turn off all LEDs before starting
  eyes(70, 0, 185);     // Set the eyes to purple
  wierd(70, 0, 185);    // Display a weird purple mouth
  smile2(70, 0, 185);   // Display a purple smile
  brows(70, 0, 185);    // Set the eyebrows to purple
}

// Displays multiple faces in quick succession for a "crazy" effect
void crazy() {
  dead();               // Display the "dead" face
  delay(50);            // Short delay
  happy();              // Display the "happy" face
  delay(50);
  talking();            // Display the "talking" face
  delay(50);
  mad();                // Display the "mad" face
  delay(50);
  smirk();              // Display the "smirk" face
  delay(50);
  eager();              // Display the "eager" face
  delay(50);
}

// Turns off all LEDs in both strips
void shutdown() {
  for (int i = 0; i < NUM_LEDS; i++) {
    strip1.setPixelColor(i, strip1.Color(0, 0, 0)); // Turn off each LED in strip1
    strip2.setPixelColor(i, strip2.Color(0, 0, 0)); // Turn off each LED in strip2
  }
  strip1.show(); // Update strip1 to reflect changes
  strip2.show(); // Update strip2 to reflect changes
}

// TOP HALF FUNCTIONS (strip1 handles the eyes and upper face)

// Displays chinky eyes in a specific pattern
void chink(int red, int green, int blue) {
  for (int i = 0; i < 4; i++) {
    strip1.setPixelColor(i, strip1.Color(red, green, blue)); // Set the first four LEDs
  }
  strip1.setPixelColor(6, strip1.Color(red, green, blue));  // Add spacing to chinky effect
  strip1.setPixelColor(11, strip1.Color(red, green, blue));
  strip1.setPixelColor(15, strip1.Color(red, green, blue));
  for (int i = 29; i < 34; i++) {
    strip1.setPixelColor(i, strip1.Color(red, green, blue)); // Add mirrored pattern
  }
  strip1.setPixelColor(35, strip1.Color(red, green, blue));
  strip1.setPixelColor(39, strip1.Color(red, green, blue));
  strip1.show(); // Update the strip
}

// Displays an X mark for "dead" eyes
void xmark(int red, int green, int blue) {
  for (int i = 0; i < 9; i++) {
    strip1.setPixelColor(i, strip1.Color(red, green, blue)); // Set the first 9 LEDs
  }
  strip1.setPixelColor(9, strip1.Color(red, green, blue));
  strip1.setPixelColor(11, strip1.Color(red, green, blue));
  strip1.setPixelColor(13, strip1.Color(red, green, blue));
  strip1.setPixelColor(15, strip1.Color(red, green, blue));
  for (int i = 25; i < 34; i++) {
    strip1.setPixelColor(i, strip1.Color(red, green, blue)); // Mirror pattern
  }
  strip1.show(); // Update the strip
}

// Displays eyebrows
void brows(int red, int green, int blue) {
  for (int i = 17; i < 25; i++) {
    strip1.setPixelColor(i, strip1.Color(red, green, blue)); // Fill eyebrow region
  }
  strip1.show();
}

// Displays eyes
void eyes(int red, int green, int blue) {
  for (int i = 9; i < 17; i++) {
    strip1.setPixelColor(i, strip1.Color(red, green, blue)); // Set left eye
  }
  for (int i = 34; i < 42; i++) {
    strip1.setPixelColor(i, strip1.Color(red, green, blue)); // Set right eye
  }
  strip1.show();
}


// BOTTOM HALF FUNCTIONS (strip2 handles the mouth and lower face)

// Displays a test pattern on the lower strip
void test(int red, int green, int blue) {
  for (int i = 7; i < 19; i++) {
    strip2.setPixelColor(i, strip2.Color(red, green, blue)); // Light up LEDs in the lower face center
  }
  for (int i = 28; i < 44; i++) {
    strip2.setPixelColor(i, strip2.Color(red, green, blue)); // Light up mirrored pattern
  }
  strip2.show(); // Update the strip
}

// Displays a "wow" or surprise mouth pattern
void wow(int red, int green, int blue) {
  for (int i = 7; i < 19; i++) {
    strip2.setPixelColor(i, strip2.Color(red, green, blue)); // Light up LEDs in a small oval pattern
  }
  for (int i = 28; i < 44; i++) {
    strip2.setPixelColor(i, strip2.Color(red, green, blue)); // Mirror the pattern
  }
  strip2.show(); // Update the strip
}

// Displays a "frown" or sad mouth
void frown(int red, int green, int blue) {
  for (int i = 5; i < 21; i++) {
    strip2.setPixelColor(i, strip2.Color(red, green, blue)); // Create the downward curve of the frown
  }
  strip2.setPixelColor(28, strip2.Color(red, green, blue)); // Add additional points to extend the frown
  strip2.setPixelColor(43, strip2.Color(red, green, blue));
  strip2.show(); // Update the strip
}

// Displays an "open" mouth pattern
void open(int red, int green, int blue) {
  for (int i = 26; i < 46; i++) {
    strip2.setPixelColor(i, strip2.Color(red, green, blue)); // Fill the lower portion with the open-mouth shape
  }
  for (int i = 7; i < 19; i++) {
    strip2.setPixelColor(i, strip2.Color(red, green, blue)); // Mirror the open mouth on the other side
  }
  strip2.show(); // Update the strip
}

// Displays a "smile" with a shorter curve
void smile1(int red, int green, int blue) {
  for (int i = 26; i < 29; i++) {
    strip2.setPixelColor(i, strip2.Color(red, green, blue)); // Light up part of the smile curve
  }
  for (int i = 43; i < 46; i++) {
    strip2.setPixelColor(i, strip2.Color(red, green, blue)); // Complete the smile with mirrored LEDs
  }
  for (int i = 7; i < 19; i++) {
    strip2.setPixelColor(i, strip2.Color(red, green, blue)); // Add middle LEDs for the smile
  }
  strip2.show(); // Update the strip
}

// Displays a full "smile" with an extended curve
void smile2(int red, int green, int blue) {
  for (int i = 26; i < 46; i++) {
    strip2.setPixelColor(i, strip2.Color(red, green, blue)); // Fill in the full smile curve
  }
  strip2.show(); // Update the strip
}

// Displays a "wide" mouth pattern
void wide(int red, int green, int blue) {
  for (int i = 0; i < 7; i++) {
    strip2.setPixelColor(i, strip2.Color(red, green, blue)); // Fill the far left LEDs of the mouth
  }
  for (int i = 19; i < 26; i++) {
    strip2.setPixelColor(i, strip2.Color(red, green, blue)); // Fill the inner left portion of the mouth
  }
  for (int i = 28; i < 44; i++) {
    strip2.setPixelColor(i, strip2.Color(red, green, blue)); // Fill the right side of the mouth
  }
  strip2.show(); // Update the strip
}

// Displays a "weird" mouth pattern
void wierd(int red, int green, int blue) {
  for (int i = 0; i < 26; i++) {
    strip2.setPixelColor(i, strip2.Color(red, green, blue)); // Fill the first half of the mouth with a pattern
  }
  strip2.show(); // Update the strip
}
