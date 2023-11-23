\name{Carseats}
\alias{Carseats}
\docType{data}
\title{Sales of Child Car Seats
%%   ~~ data name/kind ... ~~
}
\description{A simulated data set containing sales of child car seats at
  400 different stores.
%%  ~~ A concise (1-5 lines) description of the dataset. ~~
}
\usage{Carseats}
\format{
  A data frame with 400 observations on the following 11 variables.
  \describe{
    \item{\code{Sales}}{Unit sales (in thousands) at each location}
    \item{\code{CompPrice}}{Price charged by competitor at each location}
    \item{\code{Income}}{Community income level (in thousands of dollars)}
    \item{\code{Advertising}}{Local advertising budget for company at
      each location (in thousands of dollars)}
    \item{\code{Population}}{Population size in region (in thousands)}
    \item{\code{Price}}{Price company charges for car seats at each site}
    \item{\code{ShelveLoc}}{A factor with levels \code{Bad}, \code{Good}
     and \code{Medium} indicating the quality of the shelving location
     for the car seats at each site}
    \item{\code{Age}}{Average age of the local population}
    \item{\code{Education}}{Education level at each location}
    \item{\code{Urban}}{A factor with levels \code{No} and \code{Yes} to
    indicate whether the store is in an urban or rural location}
    \item{\code{US}}{A factor with levels \code{No} and \code{Yes} to
      indicate whether the store is in the US or not}
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
summary(Carseats)
lm.fit=lm(Sales~Advertising+Price,data=Carseats)
}
\keyword{datasets}
