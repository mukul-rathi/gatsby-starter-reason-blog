# Gatsby Starter Reason Blog

A starter that uses ReasonML with Gatsby. We're using the [latest v3 Reason JSX syntax](https://reasonml.github.io/reason-react/docs/en/jsx), there are also a [couple](https://github.com/ReasonVienna/reason-conf) of [other](https://github.com/jtberglund/gatsby-starter-reason) Gatsby sites using the old syntax. I would recommend you stick with the cleaner v3 syntax.

Happy coding! I've written a [blog post explaining this repo in more depth](https://mukulrathi.com/gatsby-reasonml-tutorial/).

Feel free to submit issues if you feel this can be improved!

## Getting started

This is a Gatsby starter repo so install it using the Gatsby CLI by running

`gatsby new your-gatsby-blog https://github.com/mukul-rathi/gatsby-starter-reason-blog/`

Alternatively you can fork this repo and then clone it:

`git clone https://github.com/your-github-username/gatsby-starter-reason-blog/`

Then to set up the repo:

```bash
cd your-gatsby-blog
yarn install  # install dependencies
yarn develop # or gatsby develop
```

Your site is now running at `https://localhost:8000/`! Start making changes to the source code and see the site update live!

To learn more about Gatsby head to the [Gatsby website](https://www.gatsbyjs.org/).

The structure of this repository is based off the [Gatsby starter blog](https://github.com/gatsbyjs/gatsby-starter-blog) - check that README out if you want more information about the top level structure of a typical Gatsby project.

## Tips

JS interop with Reason can be a little messy at times. [This article](https://reasonml.github.io/docs/en/converting-from-js) helps you convert from JS. If `localhost:8000` displays uncaught TypeError messages when running `gatsby develop` but your Reason code compiles, check your JS-Reason bindings (imports/exports). :)

`src/utils/gatsby.re` contains type wrappers for some Gatsby React components like `<Link/>` and `<Helmet/>`.

## GraphQL workarounds

Gatsby's GraphQL parser only works with JS files. So if you have a StaticQuery in your component, you need to write raw JS (graphql templated string), and wrap it in `[%bs.raw]`.

```reason
useStaticQuery([%bs.raw] {|
graphql`
...
`
|}]);
```

Gatsby also preprocesses GraphQL queries **before** BuckleScript compilation, and ignores queries in Reason files. To get around this, we pre-compile Reason files (see `yarn build` in the `package.json`) and then to use the component in a JS React component, import the BuckleScript compiled file (a hack, I know).

```diff
- import Foo from "./foo.re"
+ import Foo from "./foo.bs"
```

This also means we can't use page queries, so the only workaround is to wrap the ReasonReact component in a JS React Component. E.g. see `src/templates/blog-post.js`:

```js
import { graphql } from "gatsby"
import BlogPost from "./blogPost.bs"

export default BlogPost

export const pageQuery = graphql`
 ...
 `
```

And yes, another quirk of the Gatsby GraphQL parser means you can't just write `export {default} from "./blogPost.bs"` you need to import the component and then export it again.
