let x = 10;
let y = <div id="hello" />;

[@bs.module "react"]
external createElement:
  (Js.t({..} as 'a) => ReasonReact.reactElement, Js.t({..} as 'a)) =>
  ReasonReact.reactElement =
  "";


let component = React.reasonToJs(AnotherCounter.c);

let el = createElement(component, {"initialValue": 42});
ReactDOMRe.renderToElementWithId(el, "root");
