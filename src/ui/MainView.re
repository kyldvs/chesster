open Revery;
open Revery.Math;
open Revery.UI;
open Revery.UI.Components;

let textStyle =
  Style.[
    color(Colors.white),
    fontFamily("Roboto-Regular.ttf"),
    fontSize(24),
  ];

let containerStyle =
  Style.[
    position(`Absolute),
    justifyContent(`Center),
    alignItems(`Center),
    bottom(0),
    top(0),
    left(0),
    right(0),
  ];

let innerStyle = Style.[flexDirection(`Row), alignItems(`FlexEnd)];

let createElement = (~children: list(unit), _) => {
  let element =
    <View style=containerStyle>
      <View style=innerStyle>
        <Padding padding=8>
          <Text style=textStyle text="Hello world!" />
        </Padding>
      </View>
      <ChessBoard />
    </View>;
  element;
};
