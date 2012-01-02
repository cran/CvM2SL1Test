cvmtsl1.test = function(x, y)
.C("CvMTestStat", 
as.double(x), 
as.integer(length(x)),  
as.double(y), 
as.integer(length(y)),  
testscore = double(1))$testscore
#{
# Purpose: compute the (L1-version) Cramer-von Mises test score for the two samples x and y
# Arguments: x -- a sample
#            y -- another sample
# Output:    the Cramer-von Mises test score (L1 version)
# OutPut = .C("CvMTestStat", as.double(x), as.integer(length(x)),  as.double(y), as.integer(length(y)),  testscore = as.double(1))
# return (OutPut$testscore)   
#}