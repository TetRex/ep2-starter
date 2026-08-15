# `lib/` — your libraries live here

PlatformIO automatically finds any library you drop in this folder (each in its
own subfolder).

## Session 4: your Edge Impulse model

When you export your trained model from Edge Impulse as an **Arduino library**
(a `.zip`), unzip it **here**. You'll get a folder like:

```
lib/
└── your-project_inferencing/
    ├── src/
    ├── model-parameters/
    └── ...
```

Then, in `src/main.cpp`, `#include <your-project_inferencing.h>` (the exact name
matches the folder). See `examples/session04_deploy.cpp` for the full sketch.

If includes don't resolve, add `lib_ldf_mode = deep+` to `platformio.ini`.
