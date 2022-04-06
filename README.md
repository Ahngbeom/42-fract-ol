# Fract-ol [![bahn's 42 fract-ol Score](https://badge42.vercel.app/api/v2/cl1n6fb2j003009l0lfanbfyx/project/2329252)](https://github.com/JaeSeoKim/badge42)

Discover 2D programming and the psychedelic universe of fractals in this project, using minilibX.

---

## VcXsrv

- 방화벽 개인/공용 허용

- `.bashrc` | `.zshrc` VcXsrv 환경변수 설정

    `export DISPLAY=$(cat /etc/resolv.conf | grep nameserver | awk '{print $2}'):0`
        
    `export LIBGL_ALWAYS_INDIRECT=1`

    WSL2 환경에서 oh-my-zsh을 사용하고있을 경우 ~/.zshrc 파일에 위 명령어를 기입해야한다.

[VcXsrc 설치 및 설정](https://velog.io/@darkflame265/Cub3d-정리)

---

## minilibx for Linux

- [42Paris/minilibx-linux](https://github.com/42Paris/minilibx-linux)

---

## Run

- if your OS is Linux

    Windows X Server (VcXsrv or Xming) 활성화 및 실행

- Compile
  
    `make` or `make all`

- Run
    
    `./fractol`

## How to use

-   Mouse Scroll : Zoom In & Out

-   Keyboard Arrow : Viewport Transformation

-   Keyboard Numbers : Scene Transformation

-   Keyboard Numpad [4, 6] : Select RGB Color 

-   Keyboard Numpad [2, 8] : Change RGB Color Values

---
