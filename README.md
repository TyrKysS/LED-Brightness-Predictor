# LED Brightness Predictor
A project for LED brightness prediction based on text commands in the Czech language using a machine learning model. Contains code for training, model validation, and integration into Arduino and ESP32 devices. The project enables dynamic LED control using natural language.
# Requerements
- Python >= 3.12.2 (tested)

# Folter structure
```
.
├── input_data/                             # Input datasets for training and validation
│   ├── train_data.csv                      # Training dataset
│   └── val_data.csv                        # Validation dataset for model performance evaluation
├── LED_Controller/                         # Embedded code for controlling LED brightness
│   ├── data/                               # Model-exported parameters (e.g., weights, biases)
│   └── LED_Controller.ino                  # Arduino/ESP32 sketch for running the LED controller
├── logs/                                   # TensorBoard logs for monitoring the training process
│   └── fit/                                  
├── output_data/                            # Output directory for trained models
├── LED_Brightness_Prediction_Model.ipynb   # Jupyter Notebook for training and evaluating machine learning models
├── LICENSE
└── README.md
```




