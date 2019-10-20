let startsWith = (needle, haystack) => {
  let m = String.length(needle);
  let n = String.length(haystack);
  n >= m && String.sub(haystack, 0, m) == needle;
};

let filterLog = msg => {
  /* The App logs were getting pretty spammy. */
  startsWith("App", msg);
};

let init = app => {
  let _ =
    Revery.Log.listen((_, msg) =>
      if (!filterLog(msg)) {
        print_endline("LOG: " ++ msg);
      }
    );

  let win = Revery.App.createWindow(app, "Chesster");

  if (Revery.Environment.webGL) {
    Revery.Window.maximize(win);
  };

  let element = <MainView />;
  Drag.init();
  let _ = Revery.UI.start(win, element);
  Drag.refresh();
  ();
};

let run = () => Revery.App.start(init);
