let compact = (list: list(option('a))): list('a) => {
  list
  |> List.filter(o =>
       switch (o) {
       | Some(_) => true
       | None => false
       }
     )
  |> List.map(o =>
       switch (o) {
       | Some(value) => value
       | None => failwith("Unreachable.")
       }
     );
};

/**
 * Generates a list of ints between a and b exclusive.
 */
let seq = (a: int, b: int): list(int) => {
  let delta = b - a;
  let direction = delta < 0 ? (-1) : 1;
  let count = abs(delta) - 1;
  if (count > 0) {
    Array.init(count, i => a + (i + 1) * direction) |> Array.to_list;
  } else {
    [];
  };
};
