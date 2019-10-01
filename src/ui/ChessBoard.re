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

module Black = {
  let createElement = (~children, _) => {
    <Container height=64 width=64 color=black />;
  };
};

module White = {
  let createElement = (~children, _) => {
    <Container height=64 width=64 color=white />;
  };
};

module BlackRow = {
  let createElement = (~children, _) => {
    <Row>
      <Black />
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
