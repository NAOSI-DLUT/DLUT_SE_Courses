\name{Credit}
\alias{Credit}
\docType{data}
\title{Credit Card Balance Data
%%   ~~ data name/kind ... ~~
}
\description{A simulated data set containing information on ten thousand
  customers. The aim here is to predict which customers will default on
  their credit card debt.
%%  ~~ A concise (1-5 lines) description of the dataset. ~~
}
\usage{Credit}
\format{
  A data frame with 10000 observations on the following 4 variables.
  \describe{
    \item{\code{ID}}{Identification}
    \item{\code{Income}}{Income in $10,000's}    
    \item{\code{Limit}}{Credit limit}
    \item{\code{Rating}}{Credit rating}
    \item{\code{Cards}}{Number of credit cards}
    \item{\code{Age}}{Age in years}  
    \item{\code{Education}}{Number of years of education} 
    \item{\code{Gender}}{A factor with levels \code{Male} and \code{Female}}
    \item{\code{Student}}{A factor with levels \code{No} and \code{Yes}
      indicating whether the individual was a student}
    \item{\code{Married}}{A factor with levels \code{No} and \code{Yes}
      indicating whether the individual was married}
    \item{\code{Ethnicity}}{A factor with levels \code{African American}, \code{Asian}, and \code{Caucasian}
      indicating the individual's ethnicity}
    \item{\code{Balance}}{Average credit card balance in $.}
  }
}
\source{Simulated data, with thanks to Albert Kim for pointing out that
  this was omitted, and supplying the data and man documentation page on
  Oct 19, 2017
%%  ~~ reference to a publication or URL from which the data were obtained ~~
}
\references{
  James, G., Witten, D., Hastie, T., and Tibshirani, R. (2013)
  \emph{An Introduction to Statistical Learning with applications in R},
  \url{www.StatLearning.com},
  Springer-Verlag, New York
}
\examples{
summary(Credit)
lm(Balance ~ Student + Limit, data=Credit)
}
\keyword{datasets}
