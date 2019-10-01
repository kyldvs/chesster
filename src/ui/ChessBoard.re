open Chess;
open Revery;
open Revery.UI;
open Revery.UI.Components;

let isOdd = (rank: rank) => {
  switch (rank) {
  | One
  | Three
  | Five
  | Seven => true
  | Two
  | Four
  | Six
  | Eight => false
  };
};

let isDark = (rank: rank, file: file) => {
  switch (file) {
  | A
  | C
  | E
  | G => isOdd(rank)
  | B
  | D
  | F
  | H => !isOdd(rank)
  };
};

let getSrc = (piece: coloredPiece) => {
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
  };
};

let black = Color.hex("#AE734B");
let white = Color.hex("#F1D0A1");
let pieceStyle = Style.[width(64), height(64)];
let centered = Style.[justifyContent(`Center), alignItems(`Center)];
let boxShadow =
  Style.BoxShadow.make(
    ~xOffset=-8.,
    ~yOffset=-8.,
    ~blurRadius=20.,
    ~spreadRadius=0.,
    ~color=Colors.grey,
    (),
  );

let renderSquare = (rank: rank, file: file, piece: option(coloredPiece)) => {
  let color = isDark(rank, file) ? black : white;

  let children =
    switch (piece) {
    | Some(piece) =>
      let src = getSrc(piece);
      let view = <View style=centered> <Image style=pieceStyle src /> </View>;
      [view];
    | None => []
    };

  <Container height=64 width=64 color> ...children </Container>;
};

module Square = {
  let createElement = (~rank, ~file, ~children: list(coloredPiece), _) => {
    let piece =
      switch (children) {
      | [] => None
      | [x] => Some(x)
      /* TODO: What is the revery way to raise an exception? */
      | _ => failwith("Error: Squares cannot have multiple pieces.")
      };
    renderSquare(rank, file, piece);
  };
};

let createElement = (~children, _) => {
  <BoxShadow boxShadow>
    <Container height=512 width=512>
      <Row>
        <Square rank=Eight file=A> BlackRook </Square>
        <Square rank=Eight file=B> BlackKnight </Square>
        <Square rank=Eight file=C> BlackBishop </Square>
        <Square rank=Eight file=D> BlackQueen </Square>
        <Square rank=Eight file=E> BlackKing </Square>
        <Square rank=Eight file=F> BlackBishop </Square>
        <Square rank=Eight file=G> BlackKnight </Square>
        <Square rank=Eight file=H> BlackRook </Square>
      </Row>
      <Row>
        <Square rank=Seven file=A> BlackPawn </Square>
        <Square rank=Seven file=B> BlackPawn </Square>
        <Square rank=Seven file=C> BlackPawn </Square>
        <Square rank=Seven file=D> BlackPawn </Square>
        <Square rank=Seven file=E> BlackPawn </Square>
        <Square rank=Seven file=F> BlackPawn </Square>
        <Square rank=Seven file=G> BlackPawn </Square>
        <Square rank=Seven file=H> BlackPawn </Square>
      </Row>
      <Row>
        <Square rank=Six file=A />
        <Square rank=Six file=B />
        <Square rank=Six file=C />
        <Square rank=Six file=D />
        <Square rank=Six file=E />
        <Square rank=Six file=F />
        <Square rank=Six file=G />
        <Square rank=Six file=H />
      </Row>
      <Row>
        <Square rank=Five file=A />
        <Square rank=Five file=B />
        <Square rank=Five file=C />
        <Square rank=Five file=D />
        <Square rank=Five file=E />
        <Square rank=Five file=F />
        <Square rank=Five file=G />
        <Square rank=Five file=H />
      </Row>
      <Row>
        <Square rank=Four file=A />
        <Square rank=Four file=B />
        <Square rank=Four file=C />
        <Square rank=Four file=D />
        <Square rank=Four file=E />
        <Square rank=Four file=F />
        <Square rank=Four file=G />
        <Square rank=Four file=H />
      </Row>
      <Row>
        <Square rank=Three file=A />
        <Square rank=Three file=B />
        <Square rank=Three file=C />
        <Square rank=Three file=D />
        <Square rank=Three file=E />
        <Square rank=Three file=F />
        <Square rank=Three file=G />
        <Square rank=Three file=H />
      </Row>
      <Row>
        <Square rank=Two file=A> WhitePawn </Square>
        <Square rank=Two file=B> WhitePawn </Square>
        <Square rank=Two file=C> WhitePawn </Square>
        <Square rank=Two file=D> WhitePawn </Square>
        <Square rank=Two file=E> WhitePawn </Square>
        <Square rank=Two file=F> WhitePawn </Square>
        <Square rank=Two file=G> WhitePawn </Square>
        <Square rank=Two file=H> WhitePawn </Square>
      </Row>
      <Row>
        <Square rank=One file=A> WhiteRook </Square>
        <Square rank=One file=B> WhiteKnight </Square>
        <Square rank=One file=C> WhiteBishop </Square>
        <Square rank=One file=D> WhiteQueen </Square>
        <Square rank=One file=E> WhiteKing </Square>
        <Square rank=One file=F> WhiteBishop </Square>
        <Square rank=One file=G> WhiteKnight </Square>
        <Square rank=One file=H> WhiteRook </Square>
      </Row>
    </Container>
  </BoxShadow>;
};
