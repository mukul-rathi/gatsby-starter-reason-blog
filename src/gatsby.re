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

module Helmet = {
  type metaT =
    option(
      array({
        .
        "name": string,
        "content": string,
      }),
    );
  [@bs.module "react-helmet"] [@react.component]
  external make:
    (
      ~title: option(string)=?,
      ~titleTemplate: option(string)=?,
      ~htmlAttributes: option('a)=?,
      ~meta: metaT=?,
      ~children: option(React.element)=?
    ) =>
    React.element =
    "default";
};

/* old reason react imports (v2 syntax)
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