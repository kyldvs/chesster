open Revery;
open Revery.UI;
open Revery.UI.Components;

module Black = {
  let createElement = (~children, _) => {
    <Container height=64 width=64 color=Colors.black />;
  };
};

module White = {
  let createElement = (~children, _) => {
    <Container height=64 width=64 color=Colors.white />;
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
  <Container height=512 width=512>
    <WhiteRow />
    <BlackRow />
    <WhiteRow />
    <BlackRow />
    <WhiteRow />
    <BlackRow />
    <WhiteRow />
    <BlackRow />
  </Container>;
};
