type component('props, 'hooksResults) = {
  render: ('props, 'hooksResults) => ReasonReact.reactElement,
  hooks: 'props => 'hooksResults,
};

let reasonToJs = (component, props) => {
  let hooksResult = component.hooks(props);
  component.render(props, hooksResult);
};