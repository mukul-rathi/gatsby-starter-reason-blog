module Link = Gatsby.Link;

[@bs.module "../utils/typography.js"]
external rhythm: float => string = "rhythm";

type scaleReturnType = {
  fontSize: string,
  lineHeight: string,
};

[@bs.module "../utils/typography.js"]
external scale: float => scaleReturnType = "scale";

[@bs.val] external pathPrefix: string = "__PATH_PREFIX__";

type locationType = {pathname: string};

[@react.component]
let make = (~location: locationType, ~title, ~children) => {
  let rootPath = pathPrefix ++ "/";
  let header =
    if (location.pathname === rootPath) {
      <h1
        style={
          ReactDOMRe.Style.make(
            ~fontSize=scale(1.5).fontSize,
            ~lineHeight=scale(1.5).lineHeight,
            ~marginBottom=rhythm(1.5),
            ~marginTop="0",
            (),
          )
        }>
        <Link
          style={
            ReactDOMRe.Style.make(
              ~boxShadow="none",
              ~textDecoration="none",
              ~color="inherit",
              (),
            )
          }
          _to="/">
          {React.string(title)}
        </Link>
      </h1>;
    } else {
      <h3
        style={
          ReactDOMRe.Style.make(
            ~fontFamily="Montserrat, sans-serif",
            ~marginTop="0",
            (),
          )
        }>
        <Link
          style={
            ReactDOMRe.Style.make(
              ~boxShadow="none",
              ~textDecoration="none",
              ~color="inherit",
              (),
            )
          }
          _to="/">
          {React.string(title)}
        </Link>
      </h3>;
    };
  <div
    style={
      ReactDOMRe.Style.make(
        ~marginLeft="auto",
        ~marginRight="auto",
        ~maxWidth=rhythm(24.),
        ~padding=rhythm(1.5) ++ " " ++ rhythm(0.75),
        (),
      )
    }>
    <header> header </header>
    <main> children </main>
    <footer>
      {React.string("Built with ")}
      <a href="https://www.gatsbyjs.org"> {React.string("Gatsby")} </a>
    </footer>
  </div>;
};

React.setDisplayName(make, "Layout");

let default = make;