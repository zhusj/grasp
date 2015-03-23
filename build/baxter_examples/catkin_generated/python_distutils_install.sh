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

cd "/home/pracsys/grasp/src/baxter_examples"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
/usr/bin/env \
    PYTHONPATH="/home/pracsys/grasp/install/lib/python2.7/dist-packages:/home/pracsys/grasp/build/lib/python2.7/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/pracsys/grasp/build" \
    "/usr/bin/python" \
    "/home/pracsys/grasp/src/baxter_examples/setup.py" \
    build --build-base "/home/pracsys/grasp/build/baxter_examples" \
    install \
    $DESTDIR_ARG \
    --install-layout=deb --prefix="/home/pracsys/grasp/install" --install-scripts="/home/pracsys/grasp/install/bin"
