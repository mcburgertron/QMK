# Hub16 Default Keymap (visual)

Legend:
- Encoder turns: left = volume down/up, right = previous/next track.
- Encoder presses (layer 0): left = Mute, right = Play/Pause.
- `Hold→LED` = momentary access to Layer 1 (LED control).

Base (Layer 0)
```
Enc: [Mute] [Play/Pause]
R0:  7      8      9      *
R1:  4      5      6      -
R2:  1      2      3      +
R3:  Hold→LED  0   .      Enter
```

LED Control (Layer 1)
```
Enc: [Transparent] [Transparent]
R0:  —      Next   Prev   Toggle
R1:  Bright- Bright+ Hue-  Hue+
R2:  Sat-    Sat+   —      —
R3:  —       —      Boot   —
```

Notes
- LED actions use QMK underglow controls: Next/Prev = cycle mode, Toggle = on/off, Bright/Hue/Sat +/- adjust those values.
- Encoder functions stay the same on this layer (not overridden).
