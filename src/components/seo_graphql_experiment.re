/**
 * SEO component that queries for data with
 *  Gatsby's useStaticQuery React hook
 *
 * See: https://www.gatsbyjs.org/docs/use-static-query/
 */



module Helmet = Gatsby.Helmet;

[@bs.module "gatsby"] external useStaticQuery: string => 'a = "useStaticQuery";


[@bs.module "gatsby"] external graphql : 'a  = "graphql"; /* this doesn't seem to do anything, so raw  imported it below */
[%%bs.raw {| import  {graphql}  from "gatsby" |}]

[@react.component]
let make = (~description, ~lang, ~meta, ~title) => {
  let query =
    useStaticQuery(
        [%raw {| graphql`
      query {
        site {
          siteMetadata {
            title
            description
            author
          }
        }
      }
    `|}]
    );
    let siteMetadata = query##site##siteMetadata;
  let metaDescription =
    switch (description) {
    | Some(descriptionVal) => descriptionVal
    | None => siteMetadata##description
    };
  let htmlAttributes: {. lang: string} = {
    pub lang =
    (  switch (lang) {
      | Some(langVal) => langVal
      | None => "en"
      }
    )
  };
  let metaTags = [%bs.raw {|  /* TODO: convert to ReasonML types */
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
          content: site.siteMetadata.author,
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
    |}];
    let titleTemplate="%s | " ++ siteMetadata##title;
  <Helmet
    htmlAttributes
    title
    titleTemplate
    meta=metaTags
  />
};

React.setDisplayName(make, "SEO");

let default = make;