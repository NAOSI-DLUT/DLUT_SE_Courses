\name{Wage}
\alias{Wage}
\docType{data}
\title{Mid-Atlantic Wage Data
%%   ~~ data name/kind ... ~~
}
\description{Wage and other data for a group of 3000 male workers in the
  Mid-Atlantic region. 
%%  ~~ A concise (1-5 lines) description of the dataset. ~~
}
\usage{Wage}
\format{
  A data frame with 3000 observations on the following 11 variables.
  \describe{
    \item{\code{year}}{Year that wage information was recorded}
    \item{\code{age}}{Age of worker}
    \item{\code{maritl}}{A factor with levels \code{1. Never Married}
      \code{2. Married} \code{3. Widowed} \code{4. Divorced} and
      \code{5. Separated} indicating marital status}
    \item{\code{race}}{A factor with levels \code{1. White}
      \code{2. Black} \code{3. Asian} and \code{4. Other} indicating race}
    \item{\code{education}}{A factor with levels \code{1. < HS Grad}
      \code{2. HS Grad} \code{3. Some College} \code{4. College Grad}
      and \code{5. Advanced Degree} indicating education level}
    \item{\code{region}}{Region of the country (mid-atlantic only)}
    \item{\code{jobclass}}{A factor with levels \code{1. Industrial} and
      \code{2. Information} indicating type of job}
    \item{\code{health}}{A factor with levels \code{1. <=Good} and
      \code{2. >=Very Good} indicating health level of worker}
    \item{\code{health_ins}}{A factor with levels \code{1. Yes} and
      \code{2. No} indicating whether worker has health insurance}
    \item{\code{logwage}}{Log of workers wage}
    \item{\code{wage}}{Workers raw wage}
  }
}
\source{Data was manually assembled by Steve Miller, of Open BI
  (www.openbi.com), from the March 2011 Supplement to Current Population
  Survey data.
  
\url{http://thedataweb.rm.census.gov/TheDataWeb}
  

%%  ~~ reference to a publication or URL from which the data were obtained ~~
}
\references{
  James, G., Witten, D., Hastie, T., and Tibshirani, R. (2013)
  \emph{An Introduction to Statistical Learning with applications in R},
  \url{www.StatLearning.com},
  Springer-Verlag, New York
}
\examples{
summary(Wage)
lm(wage~year+age,data=Wage)
## maybe str(Wage) ; plot(Wage) ...
}
\keyword{datasets}
