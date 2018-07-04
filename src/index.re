open Reprocessing;

let white = Utils.color(~r=255, ~g=255, ~b=255, ~a=255);
let black = Utils.color(~r=0, ~g=0, ~b=0, ~a=255);

let skyColor = Utils.color(~r=79, ~g=228, ~b=239, ~a=255);
let groundColor = Utils.color(~r=187, ~g=193, ~b=204, ~a=255);
let wallColor = Utils.color(~r=101, ~g=108, ~b=119, ~a=255);
let wallColorShadow = Utils.color(~r=101 / 2, ~g=108 / 2, ~b=119 / 2, ~a=255);

let worldMap = [|
  [|1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1|],
  [|1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1|],
  [|1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1|],
  [|1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1|],
  [|1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 1|],
  [|1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1|],
  [|1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1|],
  [|1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1|],
  [|1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1|],
  [|1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1|],
  [|1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1|],
  [|1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1|],
  [|1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1|],
  [|1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1|],
  [|1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1|],
  [|1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1|],
  [|1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1|],
  [|1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1|],
  [|1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1|],
  [|1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1|],
  [|1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1|],
  [|1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1|],
  [|1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1|],
  [|1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1|],
  [|1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1|],
  [|1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1|],
  [|1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1|],
  [|1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1|],
  [|1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1|],
  [|1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1|],
  [|1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1|],
  [|1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1|],
  [|1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1|],
  [|1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1|],
  [|1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1|],
  [|1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1|],
|];

let windowWidth = 800;
let windowHeight = 600;
let walkSpeed = 2.;
let rotationSpeed = 2.;

type state = {
  position: (float, float),
  direction: (float, float),
  plane: (float, float),
  rotation: float,
};

let setup = env => {
  Env.size(~width=windowWidth, ~height=windowHeight, env);

  {position: (2., 2.), direction: (0., 1.), plane: (1., 0.), rotation: 0.};
};

let raycast = (state, env) => {
  let (playerX, playerY) = state.position;
  let (dirX, dirY) = state.direction;
  let (planeX, planeY) = state.plane;

  for (x in 0 to windowWidth) {
    let cameraX = 2. *. float_of_int(x) /. float_of_int(windowWidth) -. 1.;

    let rayDirectionX = dirX +. planeX *. cameraX;
    let rayDirectionY = dirY +. planeY *. cameraX;

    let mapX = int_of_float(floor(playerX));
    let mapY = int_of_float(floor(playerY));

    let deltaDistX = abs_float(1. /. rayDirectionX);
    let deltaDistY = abs_float(1. /. rayDirectionY);

    let (sideDistX, stepX) =
      if (rayDirectionX < 0.) {
        let sideDistX = (playerX -. float_of_int(mapX)) *. deltaDistX;
        (sideDistX, (-1));
      } else {
        let sideDistX = (float_of_int(mapX) +. 1. -. playerX) *. deltaDistX;
        (sideDistX, 1);
      };

    let (sideDistY, stepY) =
      if (rayDirectionY < 0.) {
        let sideDistY = (playerY -. float_of_int(mapY)) *. deltaDistY;
        (sideDistY, (-1));
      } else {
        let sideDistY = (float_of_int(mapY) +. 1. -. playerY) *. deltaDistY;
        (sideDistY, 1);
      };

    let rec performDDA = (hit, side, sideDistX, sideDistY, mapX, mapY) =>
      switch (hit) {
      | 0 =>
        let hit = worldMap[mapX][mapY] > 0 ? 1 : 0;

        if (hit == 1) {
          performDDA(hit, side, sideDistX, sideDistY, mapX, mapY);
        } else if (sideDistX < sideDistY) {
          let sideDistX = sideDistX +. deltaDistX;
          let mapX = mapX + stepX;
          let side = 0;

          performDDA(hit, side, sideDistX, sideDistY, mapX, mapY);
        } else {
          let sideDistY = sideDistY +. deltaDistY;
          let mapY = mapY + stepY;
          let side = 1;
          performDDA(hit, side, sideDistX, sideDistY, mapX, mapY);
        };
      | _ => (side, mapX, mapY)
      };

    let (side, mapX, mapY) = performDDA(0, 0, sideDistX, sideDistY, mapX, mapY);

    let distanceToWall =
      side == 0 ?
        (float_of_int(mapX) -. playerX +. (1. -. float_of_int(stepX)) /. 2.) /. rayDirectionX :
        (float_of_int(mapY) -. playerY +. (1. -. float_of_int(stepY)) /. 2.) /. rayDirectionY;

    let lineHeight = min(windowHeight, int_of_float(float_of_int(windowHeight) /. distanceToWall));

    if (mapX >= 0 && mapY >= 0) {
      switch (worldMap[mapX][mapY]) {
      | 1 => Draw.stroke(wallColor, env)
      | _ => ()
      };
    };

    if (side == 1) {
      switch (worldMap[mapX][mapY]) {
      | 1 => Draw.stroke(wallColorShadow, env)
      | _ => ()
      };
    };

    let startY = windowHeight / 2 - lineHeight / 2;
    let endY = startY + lineHeight;

    Draw.line(~p1=(x, startY), ~p2=(x, endY), env);
  };
};

let updatePlayer = ({direction, plane, rotation, position}, env) => {
  let deltaTime = Env.deltaTime(env);
  let (playerX, playerY) = position;

  let dirX = cos(rotation);
  let dirY = -. sin(rotation);

  let planeX = sin(rotation);
  let planeY = cos(rotation);

  let (playerX, playerY) =
    if (Env.key(Up, env)) {
      let playerX =
        if (worldMap[int_of_float(floor(playerX +. dirX *. walkSpeed *. deltaTime))][int_of_float(floor(playerY))]
            == 0) {
          playerX +. dirX *. walkSpeed *. deltaTime;
        } else {
          playerX;
        };

      let playerY =
        if (worldMap[int_of_float(floor(playerX))][int_of_float(floor(playerY +. dirY *. walkSpeed *. deltaTime))]
            == 0) {
          playerY +. dirY *. walkSpeed *. deltaTime;
        } else {
          playerY;
        };

      (playerX, playerY);
    } else {
      (playerX, playerY);
    };

  let rotation =
    if (Env.key(Left, env)) {
      rotation +. rotationSpeed *. deltaTime;
    } else if (Env.key(Right, env)) {
      rotation -. rotationSpeed *. deltaTime;
    } else {
      rotation;
    };
  ((dirX, dirY), (planeX, planeY), (playerX, playerY), rotation);
};

let draw = (state, env) => {
  Draw.background(black, env);
  Draw.fill(skyColor, env);
  Draw.rect(~pos=(0, 0), ~width=windowWidth, ~height=windowHeight / 2, env);

  Draw.fill(groundColor, env);
  Draw.rect(~pos=(0, windowHeight / 2), ~width=windowWidth, ~height=windowHeight / 2, env);

  let ((dirX, dirY), (planeX, planeY), (playerX, playerY), rotation) = updatePlayer(state, env);
  raycast(state, env);

  Draw.fill(white, env);
  Draw.rect(~pos=(12, 12), ~width=250, ~height=40, env);
  Draw.text(~body=string_of_float(Env.deltaTime(env)) ++ " fps", ~pos=(18, 18), env);
  {direction: (dirX, dirY), plane: (planeX, planeY), position: (playerX, playerY), rotation};
};

run(~setup, ~draw, ());