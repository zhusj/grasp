#!/bin/sh -x

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
    DESTDIR_ARG="--root=$DESTDIR"
fi

cd "/Users/Shaojun/catkin_ws/src/baxter_examples"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
/usr/bin/env \
    PYTHONPATH="/Users/Shaojun/catkin_ws/install/lib/python2.7/site-packages:/Users/Shaojun/catkin_ws/build/lib/python2.7/site-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/Users/Shaojun/catkin_ws/build" \
    "/usr/bin/python" \
    "/Users/Shaojun/catkin_ws/src/baxter_examples/setup.py" \
    build --build-base "/Users/Shaojun/catkin_ws/build/baxter_examples" \
    install \
    $DESTDIR_ARG \
     --prefix="/Users/Shaojun/catkin_ws/install" --install-scripts="/Users/Shaojun/catkin_ws/install/bin"
