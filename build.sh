make clean
make

os_name=$(uname -s)
case "$os_name" in
    MINGW*)
        start GD-Wii.dol
        ;;
    MSYS*)
        start GD-Wii.dol
        ;;
    *)
        open GD-Wii.dol
        ;;
esac