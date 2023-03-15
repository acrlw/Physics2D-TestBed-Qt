# Physics2D-TestBed-Qt

The testbed of Physics2D based on Qt.

# Build

Use [XMake](https://github.com/xmake-io/xmake) to build project:

```
xmake -w
xmake install -o ./bin
```

# Requirement

- C++ 20
- Qt

# Features

- Basic GUI
- Basic Debug Drawing
  - Rigid Body
  - AABB
  - DBVH
  - Joint
- Basic 2D Camera
  - Zooming
  - Smooth Transition
  - Tracing Specified Body

# Screenshot

![bitmask](./screenshots/bitmask.png)

![bridge](./screenshots/bridge.png)

![chain](./screenshots/chain.png)

![domino](./screenshots/domino.png)

![friction](./screenshots/friction.png)

![newtoncradle](./screenshots/newtoncradle.png)

![restitution](./screenshots/restitution.png)

![stacking](./screenshots/stacking.png)

![wrecking ball](./screenshots/wrecking-ball.png)
