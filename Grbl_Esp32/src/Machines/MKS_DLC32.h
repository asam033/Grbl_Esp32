#pragma once
// // Pin assignments for the Buildlog.net MPCNC controller

#define MACHINE_NAME "MKS_DLC32 V1.0"

// The laser module fires without a low signal. This keeps the enable on
#define LVL_SHIFT_ENABLE        GPIO_NUM_23
// #define CUSTOM_CODE_FILENAME    "Custom/mpcnc_laser_module.cpp"
#define CUSTOM_CODE_FILENAME    "Custom/MKS_DLC32.cpp"

#define DEFAULT_HOMING_SQUARED_AXES (bit(X_AXIS) | bit(Y_AXIS))

// #define X_STEP_PIN      GPIO_NUM_12
// #define X2_STEP_PIN     GPIO_NUM_22  // ganged motor

// #define Y_STEP_PIN      GPIO_NUM_14
// #define Y2_STEP_PIN     GPIO_NUM_21  // ganged motor

// #define Z_STEP_PIN      GPIO_NUM_27

// #define X_DIRECTION_PIN GPIO_NUM_26
// #define X2_DIRECTION_PIN X_DIRECTION_PIN
// #define Y_DIRECTION_PIN GPIO_NUM_25
// #define Y2_DIRECTION_PIN Y_DIRECTION_PIN
// #define Z_DIRECTION_PIN GPIO_NUM_33

#define SPINDLE_TYPE            SpindleType::LASER
#define LASER_OUTPUT_PIN        GPIO_NUM_22

// #define COOLANT_MIST_PIN      GPIO_NUM_2

#define X_LIMIT_PIN             GPIO_NUM_36
#define Y_LIMIT_PIN             GPIO_NUM_35
#define Z_LIMIT_PIN             GPIO_NUM_34

// #ifndef ENABLE_SOFTWARE_DEBOUNCE   // V1P2 does not have R/C filters
//     #define ENABLE_SOFTWARE_DEBOUNCE
// #endif

#define PROBE_PIN               GPIO_NUM_2

// The default value in config.h is wrong for this controller
#ifdef INVERT_CONTROL_PIN_MASK
    #undef INVERT_CONTROL_PIN_MASK
#endif

#define INVERT_CONTROL_PIN_MASK B1110

// #define CONTROL_RESET_PIN           GPIO_NUM_34  // needs external pullup
// #define CONTROL_FEED_HOLD_PIN       GPIO_NUM_36  // needs external pullup
// #define CONTROL_CYCLE_START_PIN     GPIO_NUM_39  // needs external pullup

#define DEFAULT_STEP_PULSE_MICROSECONDS     3
#define DEFAULT_STEPPER_IDLE_LOCK_TIME      255 //  255 = Keep steppers on

#define DEFAULT_STEPPING_INVERT_MASK    0 // uint8_t
#define DEFAULT_DIRECTION_INVERT_MASK   0 // uint8_t
#define DEFAULT_INVERT_ST_ENABLE        0 // boolean
#define DEFAULT_INVERT_LIMIT_PINS       1 // boolean
#define DEFAULT_INVERT_PROBE_PIN        0 // boolean

#define DEFAULT_STATUS_REPORT_MASK 1

#define DEFAULT_JUNCTION_DEVIATION  0.01 // mm
#define DEFAULT_ARC_TOLERANCE       0.002 // mm
#define DEFAULT_REPORT_INCHES       0 // false

#define DEFAULT_SOFT_LIMIT_ENABLE 1  // 软件复位
#define DEFAULT_HARD_LIMIT_ENABLE 0  // 硬件复位

#define DEFAULT_HOMING_ENABLE           1  // false
#define DEFAULT_HOMING_DIR_MASK         3 // move positive dir Z,negative X,Y
#define DEFAULT_HOMING_FEED_RATE        100.0 // mm/min
#define DEFAULT_HOMING_SEEK_RATE        200.0 // mm/min
#define DEFAULT_HOMING_DEBOUNCE_DELAY   250 // msec (0-65k)
#define DEFAULT_HOMING_PULLOFF          2.0 // mm

#ifdef USE_SPINDLE_RELAY
    #define DEFAULT_SPINDLE_RPM_MAX 1.0 // must be 1 so PWM duty is alway 100% to prevent relay damage
#else
    #define DEFAULT_SPINDLE_RPM_MAX 1000.0 // can be change to your spindle max
#endif

#define DEFAULT_SPINDLE_RPM_MIN 0.0 // rpm

#define DEFAULT_LASER_MODE 0 // false

#define DEFAULT_X_STEPS_PER_MM 200.0
#define DEFAULT_Y_STEPS_PER_MM 200.0
#define DEFAULT_Z_STEPS_PER_MM 800.0

#define DEFAULT_X_MAX_RATE 8000.0 // mm/min
#define DEFAULT_Y_MAX_RATE 8000.0 // mm/min
#define DEFAULT_Z_MAX_RATE 3000.0 // mm/min

#define DEFAULT_X_ACCELERATION 200.0 // mm/sec^2
#define DEFAULT_Y_ACCELERATION 200.0 // mm/sec^2
#define DEFAULT_Z_ACCELERATION 100.0 // mm/sec^2

#define DEFAULT_X_MAX_TRAVEL 100.0 // mm NOTE: Must be a positive value.
#define DEFAULT_Y_MAX_TRAVEL 100.0 // mm NOTE: Must be a positive value.
#define DEFAULT_Z_MAX_TRAVEL 80.0 // mm NOTE: Must be a positive value.


/*********************************************** My Code ***********************************************/
#define N_AXIS 3        // 使用三个轴，实际只使用X、Y轴，但最低定义为三个轴

/* I2S */
#define USE_I2S_OUT
#define USE_I2S_STEPS

#define I2S_OUT_BCK      GPIO_NUM_16
#define I2S_OUT_WS       GPIO_NUM_17
#define I2S_OUT_DATA     GPIO_NUM_21

// #define STEPPERS_DISABLE_PIN    I2SO(0)     // 电机驱动使能，该宏可使能三个电机驱动的EN引脚
/* X轴电机驱动引脚 */
#define X_DISABLE_PIN           I2SO(0)         // 分别定义电机驱动的使能端
#define X_DIRECTION_PIN         I2SO(2)
#define X_STEP_PIN              I2SO(1)

/* Y轴电机驱动引脚，注意IO3、4是Z轴的控制引脚 */
#define Y_DISABLE_PIN           I2SO(0)
#define Y_DIRECTION_PIN         I2SO(6)
#define Y_STEP_PIN              I2SO(5)

// #define Z_DISABLE_PIN           I2SO(0)
// #define Z_DIRECTION_PIN         I2SO(4)
// #define Z_STEP_PIN              I2SO(3)

/* 设置执行复位的轴，即只有X、Y轴复位 */
#define DEFAULT_HOMING_CYCLE_0      bit(X_AXIS)
#define DEFAULT_HOMING_CYCLE_1      bit(Y_AXIS)

// #define DEFAULT_HOMING_CYCLE_0      bit(Z_AXIS)
// #define DEFAULT_HOMING_CYCLE_1      bit(X_AXIS | Y_AXIS)

/* SD卡配置 */
#define GRBL_SPI_SS     GPIO_NUM_15
#define GRBL_SPI_MOSI   GPIO_NUM_13
#define GRBL_SPI_MISO   GPIO_NUM_12
#define GRBL_SPI_SCK    GPIO_NUM_14
#define GRBL_SPI_FREQ   4000000
#define SDCARD_DET_PIN  GPIO_NUM_39