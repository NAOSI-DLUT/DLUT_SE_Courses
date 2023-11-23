\name{Default}
\alias{Default}
\docType{data}
\title{Credit Card Default Data
%%   ~~ data name/kind ... ~~
}
\description{A simulated data set containing information on ten thousand
  customers. The aim here is to predict which customers will default on
  their credit card debt.
%%  ~~ A concise (1-5 lines) description of the dataset. ~~
}
\usage{Default}
\format{
  A data frame with 10000 observations on the following 4 variables.
  \describe{
    \item{\code{default}}{A factor with levels \code{No} and \code{Yes}
      indicating whether the customer defaulted on their debt}
    \item{\code{student}}{A factor with levels \code{No} and \code{Yes}
      indicating whether the customer is a student}
    \item{\code{balance}}{The average balance that the customer
      has remaining on their credit card after making their monthly payment}
    \item{\code{income}}{Income of customer}
  }
}
\source{Simulated data
%%  ~~ reference to a publication or URL from which the data were obtained ~~
}
\references{
  James, G., Witten, D., Hastie, T., and Tibshirani, R. (2013)
  \emph{An Introduction to Statistical Learning with applications in R},
  \url{www.StatLearning.com},
  Springer-Verlag, New York
}
\examples{
summary(Default)
glm(default~student+balance+income,family="binomial",data=Default)
}
\keyword{datasets}
