open Revery;
open Revery.Math;
open Revery.UI;
open Revery.UI.Components;

let textStyle =
  Style.[
    color(Color.hex("#222222")),
    fontFamily("Roboto-Regular.ttf"),
    fontSize(24),
  ];

let containerStyle =
  Style.[
    backgroundColor(Color.hex("#dddddd")),
    position(`Absolute),
    justifyContent(`Center),
    alignItems(`Center),
    bottom(0),
    top(0),
    left(0),
    right(0),
  ];

let innerStyle = Style.[flexDirection(`Row), alignItems(`FlexEnd)];

module MouseEnter = {
  let component = React.component("MouseEnter");
  let initialState = ();
  let reducer = (_, _) => ();
  let createElement = (~children, _) =>
    component(hooks => {
      let (state, dispatch, hooks) =
        Hooks.reducer(~initialState, reducer, hooks);
      let onMouseOver = _ => {
        Revery.Log.info("MouseEnter", "test");
      };

      let element =
        <View onMouseOver>
          <Container height=50 width=512 color=Colors.red />
        </View>;
      (hooks, element);
    });
};

let createElement = (~children: list(unit), _) => {
  let element =
    <View style=containerStyle>
      <MouseEnter />
      <View style=innerStyle>
        <Padding padding=8>
          <Text style=textStyle text="Hello world!" />
        </Padding>
      </View>
      <ChessBoard />
      <Drag.Render />
    </View>;

  element;
};
