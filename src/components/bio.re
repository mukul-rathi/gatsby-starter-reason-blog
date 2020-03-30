/**
 * Bio component that queries for data
 * with Gatsby's useStaticQuery component
 *
 * See: https://www.gatsbyjs.org/docs/use-static-query/
 */
[@bs.module "gatsby"]
external useStaticQuery: string => 'a = "useStaticQuery";
%bs.raw
{| import  {graphql}  from "gatsby" |};

module Image = Gatsby.Image;

[@bs.module "../utils/typography.js"]
external rhythm: float => string = "rhythm";

[@react.component]
let make = () => {
  let data =
    useStaticQuery(
      [%bs.raw
        {|
          graphql`
    query BioQuery {
      avatar: file(absolutePath: { regex: "/profile-pic.jpg/" }) {
        childImageSharp {
          fixed(width: 50, height: 50) {
            ...GatsbyImageSharpFixed
          }
        }
      }
      site {
        siteMetadata {
          author
          social {
            twitter
          }
        }
      }
    }
  `|}
      ],
    );
  let author = data##site##siteMetadata##author;
  let social = data##site##siteMetadata##social;
  <div
    style={
      ReactDOMRe.Style.make(~display="flex", ~marginBottom=rhythm(2.5), ())
    }>
    <Image
      fixed=data##avatar##childImageSharp##fixed
      alt=author
      style={
        ReactDOMRe.Style.make(
          ~marginRight=rhythm(0.5),
          ~marginBottom="0",
          ~minWidth="50",
          ~borderRadius="100%",
          (),
        )
      }
      imgStyle={ReactDOMRe.Style.make(~borderRadius="50%", ())}
    />
    <p>
      {React.string("Written by ")}
      <strong> author </strong>
      {React.string(" who ")}
      <a href="https://mukulrathi.com/blog"> {React.string("blogs")} </a>
      {React.string(" about the things he's
        making. ")}
      <a href={"https://twitter.com/" ++ social##twitter}>
        {React.string("You should follow him on Twitter")}
      </a>
    </p>
  </div>;
};

React.setDisplayName(make, "Bio");

let default = make;