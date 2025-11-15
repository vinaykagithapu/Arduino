# Heartbeat Sensor (KY-039)

The KY-039 heartbeat/pulse sensor is a simple optical device that detects the tiny changes in blood flow that occur each time the heart beats. It uses a pair of components:

- **Infrared LED (IR LED):** Sends infrared light into your fingertip.
- **Phototransistor:** Measures how much of that IR light is reflected back.

When your heart pumps blood, the volume of blood in your finger increases for a moment. This causes a small but measurable change in reflected IR light.
The phototransistor picks up this fluctuation and outputs an analog signal that corresponds to the pulse waveform.

## How It Works

1. IR LED shines light into your finger
2. Blood absorbs IR light depending on its volume.
3. With each heartbeat, the blood volume briefly increases.
4. The phototransistor detects this change as a small rise/fall in voltage.
5. Arduino reads this signal using `analogRead()` and processes it.

## Why KY-039 Needs Filtering

The raw signal is:
- weak
- noisy
- sensitive to ambient light
- dependent on finger pressure

So we typically use:
- smoothing filters
- threshold detection
- peak detection
- noise suppression

This allows the LED to blink only when an actual heartbeat peak is detected.

## What Makes It Cool
- Extremely cheap (~₹30–50)
- Works with only one analog pin
- Great for beginner electronics and Arduino learners
- Useful for introducing biomedical sensing, signal processing, and IoT health devices

## Common Uses
- Heartbeat visualizers (LED blink with pulse)
- Real-time pulse graphs
- Pulse-based alarms
- Fun science/DIY health monitoring projects
- Wearable device prototypes
