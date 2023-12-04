\name{Auto}
\alias{Auto}
\docType{data}
\title{
  Auto Data Set
}
\description{Gas mileage, horsepower, and other information for 392 vehicles.}
\usage{Auto}
\format{
  A data frame with 392 observations on the following 9 variables.
  \describe{
    \item{\code{mpg}}{miles per gallon}
    \item{\code{cylinders}}{Number of cylinders between 4 and 8}
    \item{\code{displacement}}{Engine displacement (cu. inches)}
    \item{\code{horsepower}}{Engine horsepower}
    \item{\code{weight}}{Vehicle weight (lbs.)}
    \item{\code{acceleration}}{Time to accelerate from 0 to 60 mph (sec.)}
    \item{\code{year}}{Model year (modulo 100)}
    \item{\code{origin}}{Origin of car (1. American, 2. European, 3. Japanese)}
    \item{\code{name}}{Vehicle name}}
  
The orginal data contained 408 observations but 16 observations with
missing values were removed.}
\source{This dataset was taken from the StatLib library which is maintained at Carnegie Mellon University. The dataset was used in the 1983 American Statistical Association Exposition.
}
\references{
  James, G., Witten, D., Hastie, T., and Tibshirani, R. (2013)
  \emph{An Introduction to Statistical Learning with applications in R},
  \url{www.StatLearning.com},
  Springer-Verlag, New York
}
\examples{
pairs(Auto)
attach(Auto)
hist(mpg)
}
\keyword{datasets}



