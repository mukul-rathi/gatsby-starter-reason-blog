module Link = Gatsby.Link;
module SEO = Seo;

[@bs.module "../utils/typography.js"]
external rhythm: float => string = "rhythm";
[@bs.module "../utils/typography.js"]
external scale:
  float =>
  {
    .
    "fontSize": string,
    "lineHeight": string,
  } =
  "scale";

[@react.component]
let make = (~data, ~pageContext, ~location) => {
  let post = data##markdownRemark;
  let siteTitle = data##site##siteMetadata##title;
  let previous = pageContext##previous;
  let next = pageContext##next;
  let description =
    switch (post##frontmatter##description) {
    | Some(postDescription) => postDescription
    | None => post##excerpt
    };
  let postTitle = post##frontmatter##title;
  <Layout location title=siteTitle>
    <SEO title=postTitle description />
    <article>
      <header>
        <h1
          style={
            ReactDOMRe.Style.make(
              ~marginTop=rhythm(1.0),
              ~marginBottom="0",
              (),
            )
          }>
          {React.string(postTitle)}
        </h1>
        <p
          style={
            ReactDOMRe.Style.make(
              ~fontSize=scale(-0.2)##fontSize,
              ~lineHeight=scale(-0.2)##lineHeight,
              ~display="block",
              ~marginBottom=rhythm(1.0),
              (),
            )
          }>
          {post##frontmatter##date}
        </p>
      </header>
      <section dangerouslySetInnerHTML={"__html": post##html} />
      <hr style={ReactDOMRe.Style.make(~marginBottom=rhythm(1.0), ())} />
      <footer> <Bio /> </footer>
    </article>
    <nav>
      <ul
        style={
          ReactDOMRe.Style.make(
            ~display="flex",
            ~flexWrap="wrap",
            ~justifyContent="space-between",
            ~listStyle="none",
            ~padding="0",
            (),
          )
        }>
        <li>
          {
            switch (Js.Nullable.toOption(previous)) {
            | Some(previousVal) =>
              /* previousVal is neither undefined nor null */
              <Link _to=previousVal##fields##slug rel="prev">
                {React.string(previousVal##frontmatter##title)}
              </Link>
            | None => React.null
            }
          }
        </li>
        <li>
          {
            switch (Js.Nullable.toOption(next)) {
            | Some(nextVal) =>
              <Link _to=nextVal##fields##slug rel="next">
                {React.string(nextVal##frontmatter##title)}
              </Link>
            | None => React.null
            }
          }
        </li>
      </ul>
    </nav>
  </Layout>;
};

React.setDisplayName(make, "BlogPostTemplate");

let default = make;