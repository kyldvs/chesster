open Chess;
open ChessTypes;

open Revery;
open Revery.UI;
open Revery.UI.Components;

type state = {
  active: option(square),
  position: ChessTypes.position,
};

type action =
  | Active(option(square))
  | TryMoveFrom(square);

let initialState: state = {active: None, position: ChessPositions.start};

let reducer = (action, state) => {
  switch (action) {
  | Active(square) =>
    /*
     * switch (square) {
     * | Some(sq) => print_endline("Active: " ++ Chess.squareToString(sq))
     * | None => print_endline("Active: None")
     * };
     */
    {...state, active: square}
  | TryMoveFrom(square) =>
    let piece = Chess.getPiece(square, state.position);
    switch (piece, state.active) {
    | (NoPiece, _) => state
    | (piece, Some(activeSquare)) =>
      let move = (piece, square, activeSquare, []);
      let position =
        try (Chess.applyMove(state.position, move)) {
        /* Use old position on any error. */
        | e =>
          print_endline(Printexc.to_string(e));
          state.position;
        };
      {...state, position};
    | _ => state
    };
  };
};

module Piece = {
  let getSrc = (piece: piece) => {
    switch (piece) {
    | BlackPawn => "pdt.svg.png"
    | BlackKnight => "ndt.svg.png"
    | BlackBishop => "bdt.svg.png"
    | BlackRook => "rdt.svg.png"
    | BlackQueen => "qdt.svg.png"
    | BlackKing => "kdt.svg.png"
    | WhitePawn => "plt.svg.png"
    | WhiteKnight => "nlt.svg.png"
    | WhiteBishop => "blt.svg.png"
    | WhiteRook => "rlt.svg.png"
    | WhiteQueen => "qlt.svg.png"
    | WhiteKing => "klt.svg.png"
    | NoPiece => ""
    };
  };

  let dragStyle = Style.[position(`Relative), top(-32), left(-32)];
  let pieceStyle = Style.[width(64), height(64)];

  let createElement =
      (~dragging=false, ~piece: piece, ~children: list(unit), _) => {
    let children =
      switch (piece) {
      | NoPiece => []
      | _ =>
        let src = getSrc(piece);
        let image = <Image style=pieceStyle src />;
        [image];
      };

    if (dragging) {
      <View style=dragStyle> ...children </View>;
    } else {
      <View> ...children </View>;
    };
  };
};

module Square = {
  let isDark = square =>
    (squareToFile(square) + squareToRank(square)) mod 2 === 0;

  let black = Color.hex("#AE734B");
  let white = Color.hex("#F1D0A1");

  let centered = Style.[justifyContent(`Center), alignItems(`Center)];

  let createElement =
      (~state, ~dispatch, ~square, ~piece: piece, ~children: list(unit), _) => {
    let color = isDark(square) ? black : white;

    let onMouseEnter = _ => {
      switch (state.active) {
      | Some(active) when active == square => ()
      | _ => dispatch(Active(Some(square)))
      };
    };

    let onMouseDown = _ => {
      switch (piece) {
      | NoPiece => ()
      | _ =>
        let pieceEl = <Piece dragging=true piece />;
        Drag.startDragging(pieceEl, ()
          /* print_endline("Square: try move from"); */
          => dispatch(TryMoveFrom(square)));
      };
    };

    <View onMouseDown onMouseEnter>
      <Container height=64 width=64 color> <Piece piece /> </Container>
    </View>;
  };
};

let boxShadow =
  Style.BoxShadow.make(
    ~xOffset=-8.,
    ~yOffset=-8.,
    ~blurRadius=20.,
    ~spreadRadius=0.,
    ~color=Colors.grey,
    (),
  );

let component = React.component("DragRender");

let createElement = (~children, _) => {
  component(hooks => {
    let (state, dispatch, hooks) =
      Hooks.reducer(~initialState, reducer, hooks);

    let position = state.position;
    let element =
      <BoxShadow boxShadow>
        <View>
          <Container height=512 width=512>
            <Row>
              <Square state dispatch square=A8 piece={position.a8} />
              <Square state dispatch square=B8 piece={position.b8} />
              <Square state dispatch square=C8 piece={position.c8} />
              <Square state dispatch square=D8 piece={position.d8} />
              <Square state dispatch square=E8 piece={position.e8} />
              <Square state dispatch square=F8 piece={position.f8} />
              <Square state dispatch square=G8 piece={position.g8} />
              <Square state dispatch square=H8 piece={position.h8} />
            </Row>
            <Row>
              <Square state dispatch square=A7 piece={position.a7} />
              <Square state dispatch square=B7 piece={position.b7} />
              <Square state dispatch square=C7 piece={position.c7} />
              <Square state dispatch square=D7 piece={position.d7} />
              <Square state dispatch square=E7 piece={position.e7} />
              <Square state dispatch square=F7 piece={position.f7} />
              <Square state dispatch square=G7 piece={position.g7} />
              <Square state dispatch square=H7 piece={position.h7} />
            </Row>
            <Row>
              <Square state dispatch square=A6 piece={position.a6} />
              <Square state dispatch square=B6 piece={position.b6} />
              <Square state dispatch square=C6 piece={position.c6} />
              <Square state dispatch square=D6 piece={position.d6} />
              <Square state dispatch square=E6 piece={position.e6} />
              <Square state dispatch square=F6 piece={position.f6} />
              <Square state dispatch square=G6 piece={position.g6} />
              <Square state dispatch square=H6 piece={position.h6} />
            </Row>
            <Row>
              <Square state dispatch square=A5 piece={position.a5} />
              <Square state dispatch square=B5 piece={position.b5} />
              <Square state dispatch square=C5 piece={position.c5} />
              <Square state dispatch square=D5 piece={position.d5} />
              <Square state dispatch square=E5 piece={position.e5} />
              <Square state dispatch square=F5 piece={position.f5} />
              <Square state dispatch square=G5 piece={position.g5} />
              <Square state dispatch square=H5 piece={position.h5} />
            </Row>
            <Row>
              <Square state dispatch square=A4 piece={position.a4} />
              <Square state dispatch square=B4 piece={position.b4} />
              <Square state dispatch square=C4 piece={position.c4} />
              <Square state dispatch square=D4 piece={position.d4} />
              <Square state dispatch square=E4 piece={position.e4} />
              <Square state dispatch square=F4 piece={position.f4} />
              <Square state dispatch square=G4 piece={position.g4} />
              <Square state dispatch square=H4 piece={position.h4} />
            </Row>
            <Row>
              <Square state dispatch square=A3 piece={position.a3} />
              <Square state dispatch square=B3 piece={position.b3} />
              <Square state dispatch square=C3 piece={position.c3} />
              <Square state dispatch square=D3 piece={position.d3} />
              <Square state dispatch square=E3 piece={position.e3} />
              <Square state dispatch square=F3 piece={position.f3} />
              <Square state dispatch square=G3 piece={position.g3} />
              <Square state dispatch square=H3 piece={position.h3} />
            </Row>
            <Row>
              <Square state dispatch square=A2 piece={position.a2} />
              <Square state dispatch square=B2 piece={position.b2} />
              <Square state dispatch square=C2 piece={position.c2} />
              <Square state dispatch square=D2 piece={position.d2} />
              <Square state dispatch square=E2 piece={position.e2} />
              <Square state dispatch square=F2 piece={position.f2} />
              <Square state dispatch square=G2 piece={position.g2} />
              <Square state dispatch square=H2 piece={position.h2} />
            </Row>
            <Row>
              <Square state dispatch square=A1 piece={position.a1} />
              <Square state dispatch square=B1 piece={position.b1} />
              <Square state dispatch square=C1 piece={position.c1} />
              <Square state dispatch square=D1 piece={position.d1} />
              <Square state dispatch square=E1 piece={position.e1} />
              <Square state dispatch square=F1 piece={position.f1} />
              <Square state dispatch square=G1 piece={position.g1} />
              <Square state dispatch square=H1 piece={position.h1} />
            </Row>
          </Container>
        </View>
      </BoxShadow>;
    (hooks, element);
  });
};
