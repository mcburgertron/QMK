# Hub16 OpenAI-FFXIV Keymap (visual)

Legend:
- Encoder turns (all layers): left = VOLD/VOLU, right = scroll down/up.
- Encoder presses per layer are shown in the diagrams (e.g., `TO OH_RPG`).
- `Hold→Layer` = momentary layer switch while held. `TO Layer` = jump to layer.
- `Shift/Esc` = tap Esc, hold Shift. `Cam Left/Right` = hold RMB and move mouse left/right.

## Game mode layers

Base (Layer 0)
```
Enc: [TO OH_RPG]         [TO OH_BASE]
R0:  Q                    W                   E                   Cam Left
R1:  A                    S                   D                   Cam Right
R2:  Ctrl                 M                   Shift/Esc           Space
R3:  F1→Hotbar1           F2→Layer2           F3→Layer3           F4→Hotbar2
```

Hotbar1 (Layer 1)
```
Enc: [—]                  [—]
R0:  1                    2                   3                   4
R1:  5                    6                   7                   8
R2:  9                    0                   -                   =
R3:  —                    —                   —                   —
```

Layer2 (Layer 2, Alt + numbers)
```
Enc: [—]                  [—]
R0:  Alt+1                Alt+2               Alt+3               Alt+4
R1:  Alt+5                Alt+6               Alt+7               Alt+8
R2:  Alt+9                Alt+0               Alt+-               Alt+=
R3:  —                    —                   —                   —
```

Layer3 (Layer 3, Ctrl+Alt + numbers)
```
Enc: [—]                  [—]
R0:  Ctl+Alt+1            Ctl+Alt+2           Ctl+Alt+3           Ctl+Alt+4
R1:  Ctl+Alt+5            Ctl+Alt+6           Ctl+Alt+7           Ctl+Alt+8
R2:  Ctl+Alt+9            Ctl+Alt+0           Ctl+Alt+-           Ctl+Alt+=
R3:  —                    —                   —                   —
```

Hotbar2 (Layer 4, Ctrl + numbers)
```
Enc: [—]                  [—]
R0:  Ctl+1                Ctl+2               Ctl+3               Ctl+4
R1:  Ctl+5                Ctl+6               Ctl+7               Ctl+8
R2:  Ctl+9                Ctl+0               Ctl+-               Ctl+=
R3:  —                    —                   —                   —
```

## One-handed layers

One-Hand Base (Layer 10)
```
Enc: [TO OH_RPG]         [TO BASE]
R0:  Q                    W                   E                   R
R1:  A                    S                   D                   F
R2:  Z                    X                   C                   V
R3:  Bspc (Hold→Mirror)   LShift (Hold→Nav)   RShift (Hold→Sym)   Space (Hold→Extra)
```

Mirror Letters (Layer 11)
```
Enc: [—]                  [—]
R0:  T                    Y                   U                   I
R1:  G                    H                   J                   K
R2:  B                    N                   M                   ,
R3:  —                    —                   —                   —
```

Extra Letters (Layer 12)
```
Enc: [—]                  [—]
R0:  O                    P                   —                   —
R1:  L                    ;                   '                   —
R2:  .                    /                   —                   —
R3:  —                    —                   —                   —
```

Symbols / Numbers (Layer 13, hold right Shift on OH_BASE)
```
Enc: [—]                  [—]
R0:  1                    2                   3                   4
R1:  5                    6                   7                   8
R2:  9                    0                   -                   =
R3:  LShift               ;                   \                   Space
```

Navigation (Layer 14, hold left Shift on OH_BASE)
```
Enc: [—]                  [—]
R0:  Esc                  Home                Up                  End
R1:  [                    Left                Down                Right
R2:  ]                    PgUp                PgDn                Del
R3:  —                    —                   —                   —
```

Function & Media (Layer 15; only active if routed there manually)
```
Enc: [—]                  [—]
R0:  F1                   F2                  F3                  F4
R1:  F5                   F6                  F7                  F8
R2:  F9                   F10                 F11                 F12
R3:  Play/Pause           Next                Prev                Mute
```

## RPGMaker layers

RPG Main (Layer 16)
```
Enc: [TO BASE]            [TO OH_BASE]
R0:  Esc                  Up                  F4                  Shift
R1:  Left                 Down                Right               Enter
R2:  Z                    X                   C                   V
R3:  —                    —                   —                   Hold→RPG Numbers
```

RPG Numbers (Layer 17)
```
Enc: [—]                  [—]
R0:  1                    2                   3                   4
R1:  5                    6                   7                   8
R2:  9                    0                   -                   =
R3:  —                    —                   —                   —
```

Notes
- Encoder turns are global: left = volume, right = scroll wheel.
- `Cam Left/Right` keys hold right mouse button while moving mouse left/right.
- Momentary layer keys (`Hold→…`) return to the previous layer when released; `TO …` jumps layers until changed again.
