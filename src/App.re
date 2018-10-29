let x = 10;
let y = <div id="hello" />;

/* [@lint.enforceLinearity] */
[@bs.module "react"] external useState: 'a => ('a, (. 'a) => unit) = "";
[@bs.module "react"]
external createElement:
  ((. Js.t({..} as 'a)) => ReasonReact.reactElement, Js.t({..} as 'a)) =>
  ReasonReact.reactElement =
  "";

module ReasonReact = {
  include ReasonReact;
  let element = (~key=?, ~ref=?, element) => element;
}

module Just = {
  let justAnotherCounter = (. props: {. "initialValue": int}) => {
    let (count, setCount) = useState(props##initialValue);

    <div>
      <h1> {ReasonReact.string(string_of_int(count))} </h1>
      <button onClick={_evt => setCount(. count + 1)}>
        {ReasonReact.string("Count Up To The Moon")}
      </button>
    </div>;
  };

  let make = (~initialValue, _children) => createElement(justAnotherCounter, {"initialValue": initialValue});
};

module M = {
  let make = (~a, _) => failwith("");
};

let m = <div> <Just initialValue=10 /> </div>;

ReactDOMRe.renderToElementWithId(m, "root");
