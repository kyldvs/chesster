let init = app => {
  let win = Revery.App.createWindow(app, "Chesster");
  let element = <MainView />;
  Drag.init();
  let _ = Revery.UI.start(win, element);
  Drag.refresh();
  ();
};

let run = () => Revery.App.start(init);
