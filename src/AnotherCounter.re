[@bs.module "react"] external useState: 'a => ('a, (. 'a) => unit) = "";

type props = {. "initialValue": int};

let c = {
  React.hooks: (props: props) => useState(props##initialValue),
  render: (_props, (count, setCount)) =>
    <div>
      <h1> {ReasonReact.string(string_of_int(count))} </h1>
      <button onClick={_evt => setCount(. count + 1)}>
        {ReasonReact.string("Count Up To Theeee Moon")}
      </button>
    </div>,
};