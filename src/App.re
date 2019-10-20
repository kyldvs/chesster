let init = app => {
  let _ = Revery.Log.listen((_, msg) => print_endline("LOG: " ++ msg));

  let win = Revery.App.createWindow(app, "Chesster");

  if (Revery.Environment.webGL) {
    Revery.Window.maximize(win);
  }

  let element = <MainView />;
  Drag.init();
  let _ = Revery.UI.start(win, element);
  Drag.refresh();
  ();
};

let run = () => Revery.App.start(init);
