let x = 10;
let y = <div id="hello" />;

[@bs.module "react"] external useState: 'a => ('a, (. 'a) => unit) = "";
[@bs.module "react"]
external createElement:
  (Js.t({..} as 'a) => ReasonReact.reactElement, Js.t({..} as 'a)) =>
  ReasonReact.reactElement =
  "";

let justAnotherCounter = (props: {. "initialValue": int}) => {
  let (count, setCount) = useState(props##initialValue);

  <div>
    <h1> {ReasonReact.string(string_of_int(count))} </h1>
    <button onClick={_evt => setCount(. count + 1)}>
      {ReasonReact.string("Count Up To The Moon")}
    </button>
  </div>;
};

let el = createElement(justAnotherCounter, {"initialValue": 42});
ReactDOMRe.renderToElementWithId(el, "root");
