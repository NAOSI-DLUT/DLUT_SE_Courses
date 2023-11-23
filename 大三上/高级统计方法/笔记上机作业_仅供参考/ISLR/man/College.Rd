\name{College}
\alias{College}
\docType{data}
\title{U.S. News and World Report's College Data
%%   ~~ data name/kind ... ~~
}
\description{Statistics for a large number of US Colleges from the 1995
  issue of US News and World Report.
%%  ~~ A concise (1-5 lines) description of the dataset. ~~
}
\usage{College}
\format{
  A data frame with 777 observations on the following 18 variables.
  \describe{
    \item{\code{Private}}{A factor with levels \code{No} and \code{Yes}
      indicating private or public university}
    \item{\code{Apps}}{Number of applications received}
    \item{\code{Accept}}{Number of applications accepted}
    \item{\code{Enroll}}{Number of new students enrolled}
    \item{\code{Top10perc}}{Pct. new students from top 10\% of H.S. class}
    \item{\code{Top25perc}}{Pct. new students from top 25\% of H.S. class}
    \item{\code{F.Undergrad}}{Number of fulltime undergraduates}
    \item{\code{P.Undergrad}}{Number of parttime undergraduates}
    \item{\code{Outstate}}{Out-of-state tuition}
    \item{\code{Room.Board}}{Room and board costs}
    \item{\code{Books}}{Estimated book costs}
    \item{\code{Personal}}{Estimated personal spending}
    \item{\code{PhD}}{Pct. of faculty with Ph.D.'s}
    \item{\code{Terminal}}{Pct. of faculty with terminal degree}
    \item{\code{S.F.Ratio}}{Student/faculty ratio}
    \item{\code{perc.alumni}}{Pct. alumni who donate}
    \item{\code{Expend}}{Instructional expenditure per student}
    \item{\code{Grad.Rate}}{Graduation rate}
  }
}
\source{This dataset was taken from the StatLib library which is
  maintained at Carnegie Mellon University. The dataset was used in the
  ASA Statistical Graphics Section's 1995 Data Analysis Exposition.
%%  ~~ reference to a publication or URL from which the data were obtained ~~
}
\references{
  James, G., Witten, D., Hastie, T., and Tibshirani, R. (2013)
  \emph{An Introduction to Statistical Learning with applications in R},
  \url{www.StatLearning.com},
  Springer-Verlag, New York
}
\examples{
summary(College)
lm(Apps~Private+Accept,data=College)
}
\keyword{datasets}
