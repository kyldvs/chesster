open Chess;
open ChessTypes;

open Revery;
open Revery.UI;
open Revery.UI.Components;

type state = {
  dragged: option(square),
  legalMovesForDragged: list(square),
  hovered: option(square),
  position: ChessTypes.position,
};

type action =
  | Dragged(option(square))
  | Hovered(option(square))
  | TryMoveFrom(square);

let initialState: state = {
  dragged: None,
  legalMovesForDragged: [],
  hovered: None,
  position: ChessPositions.start,
};

let reducer = (action, state) => {
  switch (action) {
  | Dragged(square) =>
    let legalMoves =
      switch (square) {
      | Some(square) =>
        let untested = Chess.getLegalMoves(square, state.position);
        /* TODO: Should have a better way to get actual legal moves. */
        let tested =
          List.filter(
            stop =>
              try (
                {
                  let _ =
                    Chess.applyMove(
                      state.position,
                      (
                        Chess.getPiece(square, state.position),
                        square,
                        stop,
                        [],
                      ),
                    );
                  true;
                }
              ) {
              | _ => false
              },
            untested,
          );
        tested;
      | None => []
      };
    {...state, dragged: square, legalMovesForDragged: legalMoves};
  | Hovered(square) =>
    if (false) {
      switch (square) {
      | Some(sq) => print_endline("Hovered: " ++ Chess.squareToString(sq))
      | None => print_endline("Hovered: None")
      };
    };
    {...state, hovered: square};
  | TryMoveFrom(square) =>
    let piece = Chess.getPiece(square, state.position);
    switch (piece, state.hovered) {
    | (NoPiece, _) => state
    | (piece, Some(hoveredSquare)) =>
      let move = (piece, square, hoveredSquare, []);
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
      (
        ~dragging=false,
        ~dimmed=false,
        ~piece: piece,
        ~children: list(unit),
        _,
      ) => {
    let children =
      switch (piece) {
      | NoPiece => []
      | _ =>
        let src = getSrc(piece);
        let opacity = dimmed ? 0.35 : 1.0;
        let image = <Image style=pieceStyle opacity src />;
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
  let rankForDisplay = square => {
    let r = Chess.squareToRank(square);
    if (r >= 0 && r <= 7) {
      string_of_int(r + 1);
    } else {
      "";
    };
  };

  let fileForDisplay = square => {
    let f = Chess.squareToFile(square);
    switch (f) {
    | 0 => "a"
    | 1 => "b"
    | 2 => "c"
    | 3 => "d"
    | 4 => "e"
    | 5 => "f"
    | 6 => "g"
    | 7 => "h"
    | _ => ""
    };
  };

  let isDark = square =>
    (squareToFile(square) + squareToRank(square)) mod 2 === 0;

  let black = Color.hex("#AE734B");
  let white = Color.hex("#F1D0A1");

  let draggedDark = Color.hex("#4F5C2C");
  let draggedLight = Color.hex("#698751");

  let centered = Style.[justifyContent(`Center), alignItems(`Center)];

  let darkTextStyle =
    Style.[color(black), fontFamily("Roboto-Regular.ttf"), fontSize(12)];

  let lightTextStyle =
    Style.[color(white), fontFamily("Roboto-Regular.ttf"), fontSize(12)];

  let rankStyle = Style.[position(`Absolute), top(4), right(12)];
  let fileStyle = Style.[position(`Absolute), bottom(18), left(6)];

  let createElement =
      (
        ~state,
        ~dispatch,
        ~square,
        ~piece: piece,
        ~showRank=false,
        ~showFile=false,
        ~children: list(unit),
        _,
      ) => {
    let beingDragged = state.dragged == Some(square);
    let beingHovered = state.hovered == Some(square);
    let isLegalMove = Utils.contains(square, state.legalMovesForDragged);

    let isDark = isDark(square);
    let nonAccent = isDark ? black : white;
    let accent = isDark ? draggedDark : draggedLight;
    let color =
      if (beingDragged) {
        accent;
      } else if (beingHovered && isLegalMove) {
        accent;
      } else {
        nonAccent;
      };

    let legalMoveNoPieceStyle =
      Style.[
        position(`Absolute),
        top(22),
        left(22),
        height(0),
        width(0),
        borderRadius(10.),
        border(~color=accent, ~width=10),
      ];

    let cornerSize = 10;

    let legalMoveTopLeft =
      Style.[
        position(`Absolute),
        top(- cornerSize),
        left(- cornerSize),
        height(0),
        width(0),
        border(~color=accent, ~width=cornerSize),
        transform([Transform.Rotate(Reglm.Angle.from_degrees(45.))]),
      ];

    let legalMoveTopRight =
      Style.[
        position(`Absolute),
        top(- cornerSize),
        right(- cornerSize),
        height(0),
        width(0),
        border(~color=accent, ~width=cornerSize),
        transform([Transform.Rotate(Reglm.Angle.from_degrees(45.))]),
      ];

    let legalMoveBottomLeft =
      Style.[
        position(`Absolute),
        bottom(- cornerSize),
        left(- cornerSize),
        height(0),
        width(0),
        border(~color=accent, ~width=cornerSize),
        transform([Transform.Rotate(Reglm.Angle.from_degrees(45.))]),
      ];

    let legalMoveBottomRight =
      Style.[
        position(`Absolute),
        bottom(- cornerSize),
        right(- cornerSize),
        height(0),
        width(0),
        border(~color=accent, ~width=cornerSize),
        transform([Transform.Rotate(Reglm.Angle.from_degrees(45.))]),
      ];

    /* Reversed so text is visible. */
    let textStyle = isDark ? lightTextStyle : darkTextStyle;

    let onMouseEnter = _ => {
      switch (state.hovered) {
      | Some(hovered) when hovered == square => ()
      | _ => dispatch(Hovered(Some(square)))
      };
    };

    let onMouseDown = _ => {
      switch (piece) {
      | NoPiece => ()
      | _ =>
        let pieceEl = <Piece dragging=true piece />;
        Drag.startDragging(
          pieceEl,
          () => {
            dispatch(Dragged(None));
            dispatch(TryMoveFrom(square));
          },
        );
        dispatch(Dragged(Some(square)));
      };
    };

    let rankText =
      if (showRank) {
        let text = rankForDisplay(square);
        let el =
          <View style=rankStyle>
            <Container height=0 width=0>
              <Text text style=textStyle />
            </Container>
          </View>;
        [el];
      } else {
        [];
      };

    let fileText =
      if (showFile) {
        let text = fileForDisplay(square);
        let el =
          <View style=fileStyle>
            <Container height=0 width=0>
              <Text text style=textStyle />
            </Container>
          </View>;
        [el];
      } else {
        [];
      };

    let hasPiece = piece != NoPiece;
    let legalMoveAccents =
      if (isLegalMove) {
        if (hasPiece) {
          [
            <View style=legalMoveTopLeft />,
            <View style=legalMoveTopRight />,
            <View style=legalMoveBottomLeft />,
            <View style=legalMoveBottomRight />,
          ];
        } else {
          [<View style=legalMoveNoPieceStyle />];
        };
      } else {
        [];
      };

    /* Piece last so it renders on top. */
    let children =
      rankText
      @ fileText
      @ [<Piece piece dimmed=beingDragged />]
      @ legalMoveAccents;

    <View onMouseDown onMouseEnter>
      <ClipContainer height=64 width=64 color> ...children </ClipContainer>
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
              <Square
                state
                dispatch
                square=H8
                piece={position.h8}
                showRank=true
              />
            </Row>
            <Row>
              <Square state dispatch square=A7 piece={position.a7} />
              <Square state dispatch square=B7 piece={position.b7} />
              <Square state dispatch square=C7 piece={position.c7} />
              <Square state dispatch square=D7 piece={position.d7} />
              <Square state dispatch square=E7 piece={position.e7} />
              <Square state dispatch square=F7 piece={position.f7} />
              <Square state dispatch square=G7 piece={position.g7} />
              <Square
                state
                dispatch
                square=H7
                piece={position.h7}
                showRank=true
              />
            </Row>
            <Row>
              <Square state dispatch square=A6 piece={position.a6} />
              <Square state dispatch square=B6 piece={position.b6} />
              <Square state dispatch square=C6 piece={position.c6} />
              <Square state dispatch square=D6 piece={position.d6} />
              <Square state dispatch square=E6 piece={position.e6} />
              <Square state dispatch square=F6 piece={position.f6} />
              <Square state dispatch square=G6 piece={position.g6} />
              <Square
                state
                dispatch
                square=H6
                piece={position.h6}
                showRank=true
              />
            </Row>
            <Row>
              <Square state dispatch square=A5 piece={position.a5} />
              <Square state dispatch square=B5 piece={position.b5} />
              <Square state dispatch square=C5 piece={position.c5} />
              <Square state dispatch square=D5 piece={position.d5} />
              <Square state dispatch square=E5 piece={position.e5} />
              <Square state dispatch square=F5 piece={position.f5} />
              <Square state dispatch square=G5 piece={position.g5} />
              <Square
                state
                dispatch
                square=H5
                piece={position.h5}
                showRank=true
              />
            </Row>
            <Row>
              <Square state dispatch square=A4 piece={position.a4} />
              <Square state dispatch square=B4 piece={position.b4} />
              <Square state dispatch square=C4 piece={position.c4} />
              <Square state dispatch square=D4 piece={position.d4} />
              <Square state dispatch square=E4 piece={position.e4} />
              <Square state dispatch square=F4 piece={position.f4} />
              <Square state dispatch square=G4 piece={position.g4} />
              <Square
                state
                dispatch
                square=H4
                piece={position.h4}
                showRank=true
              />
            </Row>
            <Row>
              <Square state dispatch square=A3 piece={position.a3} />
              <Square state dispatch square=B3 piece={position.b3} />
              <Square state dispatch square=C3 piece={position.c3} />
              <Square state dispatch square=D3 piece={position.d3} />
              <Square state dispatch square=E3 piece={position.e3} />
              <Square state dispatch square=F3 piece={position.f3} />
              <Square state dispatch square=G3 piece={position.g3} />
              <Square
                state
                dispatch
                square=H3
                piece={position.h3}
                showRank=true
              />
            </Row>
            <Row>
              <Square state dispatch square=A2 piece={position.a2} />
              <Square state dispatch square=B2 piece={position.b2} />
              <Square state dispatch square=C2 piece={position.c2} />
              <Square state dispatch square=D2 piece={position.d2} />
              <Square state dispatch square=E2 piece={position.e2} />
              <Square state dispatch square=F2 piece={position.f2} />
              <Square state dispatch square=G2 piece={position.g2} />
              <Square
                state
                dispatch
                square=H2
                piece={position.h2}
                showRank=true
              />
            </Row>
            <Row>
              <Square
                state
                dispatch
                square=A1
                piece={position.a1}
                showFile=true
              />
              <Square
                state
                dispatch
                square=B1
                piece={position.b1}
                showFile=true
              />
              <Square
                state
                dispatch
                square=C1
                piece={position.c1}
                showFile=true
              />
              <Square
                state
                dispatch
                square=D1
                piece={position.d1}
                showFile=true
              />
              <Square
                state
                dispatch
                square=E1
                piece={position.e1}
                showFile=true
              />
              <Square
                state
                dispatch
                square=F1
                piece={position.f1}
                showFile=true
              />
              <Square
                state
                dispatch
                square=G1
                piece={position.g1}
                showFile=true
              />
              <Square
                state
                dispatch
                square=H1
                piece={position.h1}
                showRank=true
                showFile=true
              />
            </Row>
          </Container>
        </View>
      </BoxShadow>;
    (hooks, element);
  });
};
