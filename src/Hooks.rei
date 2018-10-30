let cloneElementOther:
  (ReasonReact.reactElement, 'props) => ReasonReact.reactElement;

module ReasonReact: {
  include (module type of ReasonReact) with type reactElement = ReasonReact.reactElement;
  let element:
    (~key: 'a=?, ~ref: 'b=?, ReasonReact.reactElement) =>
    ReasonReact.reactElement;
};

/* let setName: ((. 'props) => ReasonReact.reactElement, string) => unit;
let useState: 'a => ('a, (. 'a) => unit);
let useEffect: ((unit, unit) => unit) => unit;
let useMutationEffect: ((unit, unit) => unit) => unit;
let useLayoutEffect: ((unit, unit) => unit) => unit;
let useEffectWithoutCleanup: (unit => unit) => unit;
let useMutationEffectWithoutCleanup: (unit => unit) => unit;
let useLayoutEffectWithoutCleanup: (unit => unit) => unit;
let useCallback: (unit => 'a, 'b, unit) => 'a;
let useMemo: (unit => 'a, 'b) => 'a;
let useRef: 'a => {. "current": 'a};
let useDomRef: unit => {. "current": option(Dom.node)};
let useReducer:
  (~reducer: ('state, 'action) => 'state, ~initial: 'state) =>
  ('state, 'action => unit);
let createElement:
  (
    ~component: (. Js.t({..} as 'a)) => ReasonReact.reactElement,
    ~props: Js.t('a)
  ) =>
  ReasonReact.reactElement; */




[@bs.set] external setName: ((. 'props) => ReasonReact.reactElement, string) => unit = "displayName";

[@bs.module "react"] external useState: 'a => ('a, (. 'a) => unit) = "";

[@bs.module "react"] external useEffect: ((unit, unit) => unit) => unit = "";
[@bs.module "react"]
external useMutationEffect: ((unit, unit) => unit) => unit = "";
[@bs.module "react"]
external useLayoutEffect: ((unit, unit) => unit) => unit = "";

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

[@bs.module "react"]
external createElement:
  (
    ~component: (. Js.t({..} as 'a)) => ReasonReact.reactElement,
    ~props: Js.t({..} as 'a)
  ) =>
  ReasonReact.reactElement =
  "";