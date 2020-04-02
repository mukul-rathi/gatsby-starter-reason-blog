/**
 * SEO component that queries for data with
 *  Gatsby's useStaticQuery React hook
 *
 * See: https://www.gatsbyjs.org/docs/use-static-query/
 */
module Helmet = Gatsby.Helmet;

[@bs.module "gatsby"] external useStaticQuery: string => 'a = "useStaticQuery";

/* raw import used because no Reason support for Gatsby graphql queries */
%bs.raw
{| import  {graphql}  from "gatsby" |};

/* We can define the types of fields of JS objects, and thus use them as records in ReasonML */
type siteMetadataType = {
  title: string,
  description: string,
  author: string,
};
type siteType = {siteMetadata: siteMetadataType};
type queryResType = {site: siteType};

[@react.component]
let make = (~description, ~lang="en", ~meta=[], ~title) => {
  let data: queryResType =
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
  let siteMetadata = data.site.siteMetadata;
  let metaDescription =
    switch (description) {
    | Some(descriptionVal) => descriptionVal
    | None => siteMetadata.description
    };
  let titleTemplate = "%s | " ++ siteMetadata.title;
  let htmlAttributes = {"lang": lang};

  /* Example of embedding raw JS into our Reason code. */
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