# Fract-ol

Discover 2D programming and the psychedelic universe of fractals in this project, using minilibX.

## VcXsrv

- 방화벽 개인/공용 허용

- `.bashrc` | `.zshrc` VcXsrv 환경변수 설정

    `export DISPLAY=$(cat /etc/resolv.conf | grep nameserver | awk '{print $2}'):0`
        
    `export LIBGL_ALWAYS_INDIRECT=1`

    WSL2 환경에서 oh-my-zsh을 사용하고있을 경우 ~/.zshrc 파일에 위 명령어를 기입해야한다.

[VcXsrc 설치 및 설정](https://velog.io/@darkflame265/Cub3d-정리)