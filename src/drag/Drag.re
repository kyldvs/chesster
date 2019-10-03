open Revery;
open Revery.Math;
open Revery.UI;
open Revery.UI.Components;

let id = ref(1);
let mouseX = ref(0.);
let mouseY = ref(0.);
let didInit = ref(false);
let dispatch: ref(option(int => unit)) = ref(None);
let current: ref(option(React.syntheticElement)) = ref(None);
let onStop: ref(option(unit => unit)) = ref(None);

let refresh = () => {
  switch (dispatch.contents) {
  | Some(dispatch) =>
    incr(id);
    let _ = dispatch(id.contents);
    ();
  | None => ()
  };
};

let registerDispatch = fn =>
  if (dispatch.contents == None) {
    dispatch.contents = Some(fn);
  };

let stopDragging = () => {
  current.contents = None;
  let toCall = onStop.contents;
  onStop.contents = None;
  refresh();
  /* Do this after the refresh. */
  switch (toCall) {
  | Some(toCall) => toCall()
  | None => ()
  };
};

let onMouseMove = (mouse: NodeEvents.mouseMoveEventParams) => {
  mouseX := mouse.mouseX;
  mouseY := mouse.mouseY;
  refresh();
};

let onMouseUp = _ => {
  stopDragging();
};

let startDragging = (view, onStopFn) => {
  current.contents = Some(view);
  onStop.contents = Some(onStopFn);
  refresh();
};

let init = () => {
  ();
  print_endline("Drag::init: Initialized");
  if (!didInit.contents) {
    didInit := true;
    id := 1;
    mouseX := 0.;
    mouseY := 0.;
    let _unregister = Mouse.registerListeners(~onMouseUp, ~onMouseMove, ());
    ();
  };
};

module Render = {
  let component = React.component("DragRender");

  let initialState = 0;
  let reducer = (action, _) => action;

  let createElement = (~children, _) => {
    component(hooks => {
      let (state, dispatch, hooks) =
        Hooks.reducer(~initialState, reducer, hooks);

      registerDispatch(dispatch);

      let xRounded = int_of_float(mouseX.contents) - 1;
      let yRounded = int_of_float(mouseY.contents) - 1;

      let cursorStyle =
        Style.[position(`Absolute), top(yRounded), left(xRounded)];

      let cursor =
        switch (current.contents) {
        | Some(current) => [current]
        | None => []
        };

      /*
       * Wrap in Container with no area to prevent the item being dragged
       * from stealing mouse enter/exit events.
       */
      let element =
        <View style=cursorStyle>
          <Container width=0 height=0> ...cursor </Container>
        </View>;

      (hooks, element);
    });
  };
};
