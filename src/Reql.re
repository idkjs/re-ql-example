type module_query_t = {
  .
  "parse": Js.Json.t => {. "hello": option(string)},
  "query": ReasonApolloTypes.queryString,
  "variables": Js.Json.t,
};

[@bs.module] external gql : ReasonApolloTypes.gql = "graphql-tag";

[@bs.send]
external query :
  (ApolloClient.generatedApolloClient, module_query_t) => Js.Promise.t('a) =
  "query";

let prepareQuery = q : module_query_t => {
  "query": gql(. q##query),
  "parse": q##parse,
  "variables": q##variables,
};