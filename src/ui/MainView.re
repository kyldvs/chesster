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

let innerStyle =
  Style.[maxHeight(50), flexDirection(`Row), alignItems(`FlexEnd)];

let make = _ => {
  let element =
    <View style=containerStyle>
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
