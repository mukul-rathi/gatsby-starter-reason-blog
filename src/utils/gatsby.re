module Link = {
  [@bs.module "gatsby-link"] [@react.component]
  external make:
    (
      ~_to: string, /* "to" is a reserved keyword in Reason, BuckleScript compiles _to  -> to in raw JS (quirky I know!)  */
      ~rel: option(string)=?,
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

module Image = {
  [@bs.module "gatsby-image"] [@react.component]
  external make:
    (
      ~resolutions: option('any)=?,
      ~sizes: option('any)=?,
      ~fixed: option('any)=?,
      ~fluid: option('any)=?,
      ~title: option(string)=?,
      ~alt: option(string)=?,
      ~className: option(string)=?,
      ~critical: option(bool)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      ~imgStyle: option(ReactDOMRe.Style.t)=?,
      ~placeholderStyle: option(ReactDOMRe.Style.t)=?,
      ~placeholderClassName: option(string)=?
    ) =>
    React.element =
    "default";
};
