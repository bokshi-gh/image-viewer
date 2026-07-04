# Image Viewer

A simple image viewer written in **C** using **SDL3** and **stb_image**.

The program loads an image from the command line and renders it by drawing each pixel manually with SDL.

---

## Features

* Supports image formats handled by `stb_image` (PNG, JPEG, BMP, TGA, GIF, HDR, and more)
* Manual per-pixel rendering
* Simple command-line interface
* Minimal dependencies

---

## Getting Started

### Requirements

On Arch Linux:

```bash
sudo pacman -S gcc make pkgconf sdl3
```

### Clone the Repository

```bash
git clone https://github.com/bokshi-gh/image-viewer.git
cd image-viewer
```


### Build

Compile the project with:

```bash
make
```

This produces the executable:

```text
viewer
```

> [!NOTE]
> ## Build Notes
>
> The Makefile is written specifically for **Linux systems**.
>
> It depends on:
> - gcc
> - make
> - pkg-config
> - system-installed SDL3
>
> If you are not on Linux, you must:
> - install SDL3 manually
> - compile using your own compiler commands

### Usage

```bash
./viewer <image>
```

Example:

```bash
./viewer image.png
```

---

## How It Works

1. Initialize SDL.
2. Load an image using `stb_image`.
3. Convert the image to RGBA format.
4. Loop over every pixel.
5. Read the RGBA values from memory.
6. Draw each pixel using `SDL_RenderPoint()`.
7. Present the rendered frame.

Each pixel is accessed using:

```cpp
int index = (y * width + x) * 4;
```

where:

* `x` is the horizontal coordinate.
* `y` is the vertical coordinate.
* `width` is the image width.
* `4` represents the RGBA channels.

The color components are then read as:

```cpp
Uint8 r = pixels[index];
Uint8 g = pixels[index + 1];
Uint8 b = pixels[index + 2];
Uint8 a = pixels[index + 3];
```

---

## License

This project is licensed under the **[MIT License](LICENSE)**.

`stb_image` is part of the public-domain/MIT-licensed stb libraries. Refer to the `stb_image.h` header for its license information.
