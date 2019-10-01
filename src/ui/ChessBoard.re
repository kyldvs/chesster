open Revery;
open Revery.UI;
open Revery.UI.Components;

let black = Color.hex("#AE734B");
let white = Color.hex("#F1D0A1");
let boxShadow =
  Style.BoxShadow.make(
    ~xOffset=-8.,
    ~yOffset=-8.,
    ~blurRadius=20.,
    ~spreadRadius=0.,
    ~color=Colors.grey,
    (),
  );

let pieceStyle = Style.[width(64), height(64)];

let centered = Style.[justifyContent(`Center), alignItems(`Center)];

module BlackKing = {
  let createElement = (~children, _) => {
    <View style=centered> <Image src="kdt.svg.png" style=pieceStyle /> </View>;
  };
};

module Black = {
  let createElement = (~children, _) => {
    <Container height=64 width=64 color=black> ...children </Container>;
  };
};

module White = {
  let createElement = (~children, _) => {
    <Container height=64 width=64 color=white> ...children </Container>;
  };
};

module BlackRow = {
  let createElement = (~children, _) => {
    <Row>
      <Black> <BlackKing /> </Black>
      <White />
      <Black />
      <White />
      <Black />
      <White />
      <Black />
      <White />
    </Row>;
  };
};

module WhiteRow = {
  let createElement = (~children, _) => {
    <Row>
      <White />
      <Black />
      <White />
      <Black />
      <White />
      <Black />
      <White />
      <Black />
    </Row>;
  };
};

let createElement = (~children, _) => {
  <BoxShadow boxShadow>
    <Container height=512 width=512>
      <WhiteRow />
      <BlackRow />
      <WhiteRow />
      <BlackRow />
      <WhiteRow />
      <BlackRow />
      <WhiteRow />
      <BlackRow />
    </Container>
  </BoxShadow>;
};
