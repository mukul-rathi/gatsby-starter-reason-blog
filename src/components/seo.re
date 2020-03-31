/**
 * SEO component that queries for data with
 *  Gatsby's useStaticQuery React hook
 *
 * See: https://www.gatsbyjs.org/docs/use-static-query/
 */
module Helmet = Gatsby.Helmet;

[@bs.module "gatsby"] external useStaticQuery: string => 'a = "useStaticQuery";

[@bs.module "gatsby"] external graphql: 'a = "graphql"; /* this doesn't seem to do anything, so raw  imported it below */
%bs.raw
{| import  {graphql}  from "gatsby" |};

[@react.component]
let make = (~description, ~lang="en", ~meta=[], ~title) => {
  let query =
    useStaticQuery(
      [%bs.raw
        {|
           graphql`
            query {
        site {
          siteMetadata {
            title
            description
            author
          }
        }
      }
    `
    |}
      ],
    );
  let siteMetadata = query##site##siteMetadata;
  let metaDescription =
    switch (description) {
    | Some(descriptionVal) => descriptionVal
    | None => siteMetadata##description
    };
  let titleTemplate = "%s | " ++ siteMetadata##title;
  let htmlAttributes = {"lang": lang};
  let metaTagsFun = [%bs.raw
    {| (siteMetadata, title, metaDescription, meta) =>
      [
        {
          name: `description`,
          content: metaDescription,
        },
        {
          property: `og:title`,
          content: title,
        },
        {
          property: `og:description`,
          content: metaDescription,
        },
        {
          property: `og:type`,
          content: `website`,
        },
        {
          name: `twitter:card`,
          content: `summary`,
        },
        {
          name: `twitter:creator`,
          content: siteMetadata.author,
        },
        {
          name: `twitter:title`,
          content: title,
        },
        {
          name: `twitter:description`,
          content: metaDescription,
        },
      ].concat(meta)
      |}
  ];
  <Helmet
    title
    titleTemplate
    htmlAttributes
    meta={metaTagsFun(siteMetadata, title, metaDescription, meta)}
  />;
};

React.setDisplayName(make, "SEO");

let default = make;