module Link = {
  [@bs.module "gatsby-link"] [@react.component]
  external make:
    (
      ~to_: string,
      ~className: option(string)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      ~activeStyle: option(ReactDOMRe.Style.t)=?,
      ~activeClassName: option(string)=?,
      ~children: option(React.element)=?
    ) =>
    React.element =
    "default";
};
/* 
module Helmet = {
  [@bs.module "react-helmet"]
  external linkClass: ReasonReact.reactClass = "default";
  type metaT =
    option(
      array({
        .
        "name": string,
        "content": string,
      }),
    );
  let make =
      (~title: option(string)=?, ~bodyAttributes=?, ~meta: metaT=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=linkClass,
      ~props={
        "title": Js.Nullable.fromOption(title),
        "bodyAttributes": Js.Nullable.fromOption(bodyAttributes),
        "meta": Js.Nullable.fromOption(meta),
      },
      children,
    );
};

module SocialIcons = {
  [@bs.module "react-social-icons"]
  external linkClass: ReasonReact.reactClass = "default";
  let make =
      (
        ~urls: array(string),
        ~className: option(string)=?,
        ~color: option(string)=?,
        _children,
      ) => {
    let props = {
      "urls": urls,
      "className": Js.Nullable.fromOption(className),
      "color": Js.Nullable.fromOption(color),
    };
    ReasonReact.wrapJsForReason(~reactClass=linkClass, ~props, _children);
  };
};

module SocialIcon = {
  [@bs.module "react-social-icons"]
  external linkClass: ReasonReact.reactClass = "SocialIcon";
  let make =
      (
        ~url: string,
        ~className: option(string)=?,
        ~color: option(string)=?,
        ~network: option(string)=?,
        _children,
      ) => {
    let props = {
      "url": url,
      "className": Js.Nullable.fromOption(className),
      "color": Js.Nullable.fromOption(color),
      "network": Js.Nullable.fromOption(network),
    };
    ReasonReact.wrapJsForReason(~reactClass=linkClass, ~props, _children);
  };
}; */