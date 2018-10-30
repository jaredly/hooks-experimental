# hooks-experimental
An experiment using react's new "hooks" with ReasonReact

WARNING: Do not use for anything real.

## How to use

### 1) the package.json

NOTE: You *must* use yarn, so that we can override reason-react's react dependencies with `resolutions`.

```
  "resolutions": {
    "**/react": "16.7.0-alpha.0",
    "**/react-dom": "16.7.0-alpha.0"
  },
  "dependencies": {
    "react": "16.7.0-alpha.0",
    "react-dom": "16.7.0-alpha.0",
    "reason-react": "^0.5.3",
    "hooks-experimental": "github:jaredly/hooks-experimental"
  }
```

### 2) the bsconfig.json

Nothing special here, just add `"hooks-experimental"` to `"bs-dependencies"`.

### 3) making a component!

```re
module ReasonReact = Hooks.ReasonReact;

module FancyCounter = {
  let component = (. props: {. "initialValue": int}) => {
    let (count, setCount) = Hooks.useState(props##initialValue);

    <div>
      <h1> {ReasonReact.string(string_of_int(count))} </h1>
      <button onClick={_evt => setCount(. count + 1)}>
        {ReasonReact.string("Count Up To The Moon")}
      </button>
    </div>;
  };
  component->Hooks.setName("Just");

  let make = (~initialValue, _children) =>
    Hooks.createElement(
      ~component,
      ~props={"initialValue": initialValue},
    );
};

ReactDOMRe.renderToElementWithId(<FancyCounter initialValue=10 />, "root");
```

### 4) Hooks API

```
[@bs.module "react"] external useState: 'a => ('a, (. 'a) => unit) = "";

[@bs.module "react"] external useEffect: ((unit) => (unit => unit)) => unit = "";
[@bs.module "react"]
external useMutationEffect: ((unit) => (unit => unit)) => unit = "";
[@bs.module "react"]
external useLayoutEffect: ((unit) => (unit => unit)) => unit = "";

[@bs.module "react"]
external useEffectWithoutCleanup: (unit => unit) => unit = "useEffect";
[@bs.module "react"]
external useMutationEffectWithoutCleanup: (unit => unit) => unit = "";
[@bs.module "react"]
external useLayoutEffectWithoutCleanup: (unit => unit) => unit = "";

[@bs.module "react"] external useCallback: (unit => 'a, 'b, unit) => 'a = "";
[@bs.module "react"] external useMemo: (unit => 'a, 'b) => 'a = "";

[@bs.module "react"] external useRef: 'a => {. "current": 'a} = "";
[@bs.module "react"]
external useDomRef: unit => {. "current": option(Dom.node)} = "useRef";

[@bs.module "react"]
external useReducer:
  (~reducer: (. 'state, 'action) => 'state, ~initial: 'state) =>
  ('state, (. 'action) => unit) =
  "";
```